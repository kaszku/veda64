#!/usr/bin/env python3
"""Benchmark ARM64 disassembly: veda64_py binding vs Capstone."""

import argparse
import struct
import sys
import time
from pathlib import Path

import capstone

IMAGE_SCN_MEM_EXECUTE = 0x20000000
MACHINE_ARM64 = 0xAA64

# ── veda64_py binding ─────────────────────────────────────────────────────────

_veda64_py = None

def _try_load_binding() -> bool:
    global _veda64_py
    candidates = [
        Path(__file__).parent / '__build_arm64' / 'Release',
        Path(__file__).parent,
    ]
    for d in candidates:
        if d not in sys.path:
            sys.path.insert(0, str(d))
    try:
        import veda64_py
        _veda64_py = veda64_py
        return True
    except ImportError:
        return False

_try_load_binding()


def parse_pe(data):
    """Parse PE headers, return (sections, image_base)."""
    if len(data) < 64 or data[:2] != b'MZ':
        raise ValueError("Not a valid PE file (bad MZ signature)")

    e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
    if len(data) < e_lfanew + 4 or data[e_lfanew:e_lfanew + 4] != b'PE\0\0':
        raise ValueError("Not a valid PE file (bad PE signature)")

    coff_offset = e_lfanew + 4
    machine, num_sections, _, _, _, size_of_optional = struct.unpack_from(
        '<HHIIIH', data, coff_offset
    )

    if machine != MACHINE_ARM64:
        raise ValueError(f"Not an ARM64 PE (Machine=0x{machine:04X})")

    opt_offset = coff_offset + 20
    opt_magic = struct.unpack_from('<H', data, opt_offset)[0]
    if opt_magic == 0x20B:
        image_base = struct.unpack_from('<Q', data, opt_offset + 24)[0]
    else:
        image_base = 0

    section_table_offset = opt_offset + size_of_optional
    sections = []
    for i in range(num_sections):
        off = section_table_offset + i * 40
        name_raw = data[off:off + 8]
        name = name_raw.split(b'\0', 1)[0].decode('ascii', errors='replace')
        virtual_size, virtual_addr, raw_size, raw_ptr = struct.unpack_from(
            '<IIII', data, off + 8
        )
        characteristics = struct.unpack_from('<I', data, off + 36)[0]
        sections.append({
            'name': name,
            'virtual_size': virtual_size,
            'virtual_address': virtual_addr,
            'raw_size': raw_size,
            'raw_ptr': raw_ptr,
            'characteristics': characteristics,
        })

    return sections, image_base


def extract_code(data, sections):
    """Return (raw_bytes, words, total_insns) for all executable sections combined."""
    chunks = []
    for s in sections:
        if s['characteristics'] & IMAGE_SCN_MEM_EXECUTE:
            chunks.append(data[s['raw_ptr']:s['raw_ptr'] + s['raw_size']])

    raw = b''.join(chunks)
    num_insns = len(raw) // 4
    words = [struct.unpack_from('<I', raw, i * 4)[0] for i in range(num_insns)]
    return raw, words, num_insns


# -- Benchmarks ----------------------------------------------------------------

def bench_veda64_binding(words, iterations):
    """Benchmark veda64_py binding: decode + to_string per instruction."""
    decode = _veda64_py.decode
    times = []
    for _ in range(iterations):
        t0 = time.perf_counter()
        for w in words:
            r = decode(w)
            if r is not None:
                r.to_string()
        t1 = time.perf_counter()
        times.append(t1 - t0)
    return times


def bench_veda64_binding_decode_only(words, iterations):
    """Benchmark veda64_py binding: decode only (no string formatting)."""
    decode = _veda64_py.decode
    times = []
    for _ in range(iterations):
        t0 = time.perf_counter()
        for w in words:
            decode(w)
        t1 = time.perf_counter()
        times.append(t1 - t0)
    return times


def bench_capstone(raw, iterations):
    """Benchmark Capstone streaming over raw bytes."""
    cs = capstone.Cs(capstone.CS_ARCH_AARCH64, capstone.CS_MODE_ARM)
    cs.skipdata = True
    times = []
    for _ in range(iterations):
        t0 = time.perf_counter()
        for _ in cs.disasm(raw, 0):
            pass
        t1 = time.perf_counter()
        times.append(t1 - t0)
    return times


# -- Reporting -----------------------------------------------------------------

def fmt_time(seconds):
    if seconds < 0.001:
        return f"{seconds * 1_000_000:.0f} us"
    if seconds < 1:
        return f"{seconds * 1000:.1f} ms"
    return f"{seconds:.3f} s"


def fmt_rate(insns, seconds):
    if seconds == 0:
        return "-- insn/s"
    rate = insns / seconds
    if rate >= 1_000_000:
        return f"{rate / 1_000_000:.2f} M insn/s"
    if rate >= 1_000:
        return f"{rate / 1_000:.1f} K insn/s"
    return f"{rate:.0f} insn/s"


def print_results(label, times, num_insns):
    best = min(times)
    avg = sum(times) / len(times)
    worst = max(times)
    print(f"  {label}:")
    print(f"    Best:  {fmt_time(best):>12}  ({fmt_rate(num_insns, best)})")
    print(f"    Avg:   {fmt_time(avg):>12}  ({fmt_rate(num_insns, avg)})")
    print(f"    Worst: {fmt_time(worst):>12}  ({fmt_rate(num_insns, worst)})")
    return best


def main():
    parser = argparse.ArgumentParser(
        description='Benchmark ARM64 disassembly: veda64_py binding vs Capstone')
    parser.add_argument('pe_file', help='Path to PE executable')
    parser.add_argument('--iterations', '-n', type=int, default=3,
                        help='Number of iterations per benchmark (default: 3)')
    args = parser.parse_args()

    if _veda64_py is None:
        print("Error: veda64_py binding not found.", file=sys.stderr)
        print("Build the project first (cmake --build __build_arm64 --config Release).", file=sys.stderr)
        return 1

    pe_path = Path(args.pe_file)
    if not pe_path.is_file():
        print(f"Error: File not found: {pe_path}", file=sys.stderr)
        return 1

    data = pe_path.read_bytes()
    try:
        sections, image_base = parse_pe(data)
    except ValueError as e:
        print(f"Error: {e}", file=sys.stderr)
        return 1

    raw, words, num_insns = extract_code(data, sections)
    if num_insns == 0:
        print("Error: No executable code found.", file=sys.stderr)
        return 1

    iters = args.iterations

    print(f"File:       {pe_path.name}")
    print(f"Code:       {num_insns:,} instructions ({len(raw):,} bytes)")
    print(f"Iterations: {iters}")
    print(f"Binding:    {Path(_veda64_py.__file__).name}")
    print()

    # -- Warmup ----------------------------------------------------------------
    print("Warming up...", flush=True)
    _veda64_py.decode(0xD503201F)
    cs_warmup = capstone.Cs(capstone.CS_ARCH_AARCH64, capstone.CS_MODE_ARM)
    for _ in cs_warmup.disasm(b'\x1f\x20\x03\xd5', 0):
        pass

    # -- veda64_py binding -----------------------------------------------------
    print("Benchmarking veda64_py (decode + to_string)...", flush=True)
    binding_times = bench_veda64_binding(words, iters)

    print("Benchmarking veda64_py (decode only)...", flush=True)
    decode_times = bench_veda64_binding_decode_only(words, iters)

    # -- Capstone (streaming) --------------------------------------------------
    print("Benchmarking Capstone (streaming)...", flush=True)
    capstone_times = bench_capstone(raw, iters)

    # -- Results ---------------------------------------------------------------
    print(f"\n{'=' * 64}")
    print(f"Results ({num_insns:,} instructions, best of {iters})")
    print(f"{'=' * 64}")

    cs_best = print_results("Capstone (streaming)", capstone_times, num_insns)
    binding_best = print_results("veda64_py  (decode + to_string)", binding_times, num_insns)
    decode_best = print_results("veda64_py  (decode only)       ", decode_times, num_insns)

    print(f"\n{'-' * 64}")
    print(f"  Comparison vs Capstone (best times):")

    def cmp_line(label, t):
        if t > cs_best:
            print(f"    {label}: {t / cs_best:.1f}x slower")
        else:
            print(f"    {label}: {cs_best / t:.1f}x faster")

    cmp_line("veda64_py (decode+str) ", binding_best)
    cmp_line("veda64_py (decode only)", decode_best)

    return 0


if __name__ == '__main__':
    sys.exit(main())

#!/usr/bin/env python3
"""Benchmark ARM64 disassembly: veda64-disasm vs Capstone."""

import argparse
import struct
import subprocess
import sys
import time
from pathlib import Path

import capstone

IMAGE_SCN_MEM_EXECUTE = 0x20000000
MACHINE_ARM64 = 0xAA64
BATCH_SIZE = 2000


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

def bench_veda64(words, disasm_path, iterations, batch_size):
    """Benchmark veda64-disasm over all words."""
    times = []
    for _ in range(iterations):
        t0 = time.perf_counter()
        for batch_start in range(0, len(words), batch_size):
            batch = words[batch_start:batch_start + batch_size]
            args = [str(disasm_path)] + [f'0x{w:08X}' for w in batch]
            subprocess.run(args, capture_output=True)
        t1 = time.perf_counter()
        times.append(t1 - t0)
    return times


def measure_spawn_overhead(disasm_path, num_spawns):
    """Measure average subprocess spawn overhead by running minimal invocations."""
    t0 = time.perf_counter()
    for _ in range(num_spawns):
        subprocess.run([str(disasm_path), '0xD503201F'], capture_output=True)
    t1 = time.perf_counter()
    return (t1 - t0) / num_spawns


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


def bench_capstone_batch(raw, iterations):
    """Benchmark Capstone one instruction at a time (4-byte chunks)."""
    cs = capstone.Cs(capstone.CS_ARCH_AARCH64, capstone.CS_MODE_ARM)
    cs.skipdata = True
    num_insns = len(raw) // 4
    times = []
    for _ in range(iterations):
        t0 = time.perf_counter()
        for i in range(num_insns):
            chunk = raw[i * 4:(i + 1) * 4]
            for _ in cs.disasm(chunk, 0):
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
    worst = max(times)
    avg = sum(times) / len(times)
    print(f"  {label}:")
    print(f"    Best:  {fmt_time(best):>12}  ({fmt_rate(num_insns, best)})")
    print(f"    Avg:   {fmt_time(avg):>12}  ({fmt_rate(num_insns, avg)})")
    print(f"    Worst: {fmt_time(worst):>12}  ({fmt_rate(num_insns, worst)})")
    return best


def main():
    parser = argparse.ArgumentParser(
        description='Benchmark ARM64 disassembly: veda64-disasm vs Capstone')
    parser.add_argument('pe_file', help='Path to PE executable')
    parser.add_argument('--disasm', help='Path to veda64-disasm.exe', default=None)
    parser.add_argument('--iterations', '-n', type=int, default=3,
                        help='Number of iterations per benchmark (default: 3)')
    parser.add_argument('--batch-size', '-b', type=int, default=BATCH_SIZE,
                        help=f'Instructions per veda64-disasm invocation (default: {BATCH_SIZE})')
    args = parser.parse_args()

    pe_path = Path(args.pe_file)
    if not pe_path.is_file():
        print(f"Error: File not found: {pe_path}", file=sys.stderr)
        return 1

    if args.disasm:
        disasm_path = Path(args.disasm)
    else:
        disasm_path = Path(__file__).parent / '__build_arm64' / 'Release' / 'veda64-disasm.exe'

    if not disasm_path.is_file():
        print(f"Error: veda64-disasm not found at: {disasm_path}", file=sys.stderr)
        return 1

    batch_size = args.batch_size

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

    num_batches = (num_insns + batch_size - 1) // batch_size
    iters = args.iterations

    print(f"File: {pe_path.name}")
    print(f"Code: {num_insns:,} instructions ({len(raw):,} bytes)")
    print(f"veda64 batch size: {batch_size} ({num_batches} invocations)")
    print(f"Iterations: {iters}")
    print()

    # -- Warmup ----------------------------------------------------------------
    print("Warming up...", flush=True)
    subprocess.run([str(disasm_path), '0xD503201F'], capture_output=True)
    cs = capstone.Cs(capstone.CS_ARCH_AARCH64, capstone.CS_MODE_ARM)
    for _ in cs.disasm(b'\x1f\x20\x03\xd5', 0):
        pass

    # -- Measure subprocess spawn overhead -------------------------------------
    print("Measuring subprocess overhead...", flush=True)
    spawn_overhead = measure_spawn_overhead(disasm_path, 20)

    # -- Capstone (streaming) --------------------------------------------------
    print("Benchmarking Capstone (streaming)...", flush=True)
    cs_times = bench_capstone(raw, iters)

    # -- Capstone (per-instruction) --------------------------------------------
    print("Benchmarking Capstone (per-instruction)...", flush=True)
    cs_batch_times = bench_capstone_batch(raw, iters)

    # -- veda64-disasm ---------------------------------------------------------
    print("Benchmarking veda64-disasm (subprocess)...", flush=True)
    veda_times = bench_veda64(words, disasm_path, iters, batch_size)

    # -- Results ---------------------------------------------------------------
    veda_best = min(veda_times)
    total_spawn = spawn_overhead * num_batches
    veda_decode_est = max(veda_best - total_spawn, 0.001)

    print(f"\n{'=' * 64}")
    print(f"Results ({num_insns:,} instructions, best of {iters})")
    print(f"{'=' * 64}")

    cs_best = print_results("Capstone (streaming)", cs_times, num_insns)
    cs_batch_best = print_results("Capstone (per-instruction)", cs_batch_times, num_insns)
    print_results("veda64-disasm (total)", veda_times, num_insns)

    print(f"\n  veda64 overhead breakdown:")
    print(f"    Spawn overhead:  {fmt_time(spawn_overhead)}/process x {num_batches} = {fmt_time(total_spawn)}")
    print(f"    Estimated decode: {fmt_time(veda_decode_est)}  ({fmt_rate(num_insns, veda_decode_est)})")

    print(f"\n{'-' * 64}")
    print(f"  Comparison (best times):")

    def cmp_line(label, a, b):
        if a > b:
            print(f"    {label}: {a / b:.1f}x slower than Capstone")
        else:
            print(f"    {label}: {b / a:.1f}x faster than Capstone")

    cmp_line("veda64 total     vs Capstone streaming      ", veda_best, cs_best)
    cmp_line("veda64 total     vs Capstone per-instruction", veda_best, cs_batch_best)
    cmp_line("veda64 decode    vs Capstone streaming      ", veda_decode_est, cs_best)
    cmp_line("veda64 decode    vs Capstone per-instruction", veda_decode_est, cs_batch_best)

    return 0


if __name__ == '__main__':
    sys.exit(main())

#!/usr/bin/env python3
"""Quick decode verification tests using veda64-disasm."""
import subprocess
import sys

import os
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
DISASM = os.path.join(SCRIPT_DIR, "__build_arm64", "Release", "veda64-disasm.exe")

# (hex_encoding, expected_output_substring)
TESTS = [
    # SHRN with correct arrangement
    ("0x0f0c84e7", "shrn v7.8b, v7.8h, #4"),
    # SSHLL with correct arrangement
    ("0x0f08a4e7", "sshll v7.8h, v7.8b, #0"),
    # SHL with correct arrangement
    ("0x0f245463", "shl v3.2s, v3.2s, #4"),
    # MOVI (not confused with SHRN)
    ("0x4f008407", "movi v7.8h, #0"),
    # MOVI with LSL #8
    ("0x4f00a447", "movi v7.8h, #2, lsl #8"),
    # MOVI (not confused with SSHR)
    ("0x0f000606", "movi"),
    # UADDLP pairwise long (dest wider)
    ("0x6e202a43", "uaddlp v3.8h, v18.16b"),
    # UADALP pairwise long (dest wider)
    ("0x6e606866", "uadalp v6.4s, v3.8h"),
    # FCMPE with zero
    ("0x1e602018", "fcmpe d0, #0.0"),
    ("0x1e202018", "fcmpe s0, #0.0"),
    # FCMPE reg-to-reg
    ("0x1e602010", "fcmpe d0, d0"),
    # FCMP with zero
    ("0x1e602008", "fcmp d0, #0.0"),
    # FMOV imm8=0 -> 2.0 (NOT 0.0)
    ("0x1e601010", "fmov d16, #2.0"),
    # UQSUB vector
    ("0x6e662ce5", "uqsub v5.8h, v7.8h, v6.8h"),
    # CSINC (base form)
    ("0x1a810400", "csinc w0, w0, w1, eq"),
    # CSINC (CSET form: Rm=Rn=XZR)
    ("0x1a9f07e0", "cset w0, ne"),
    # SRSHR
    ("0x0f202444", "srshr v4.2s, v2.2s"),
    # USHLL (widening: 32-bit source)
    ("0x2f20a463", "ushll v3.2d, v3.2s, #0"),
    # USHLL (widening: another encoding)
    ("0x2f20a4a7", "ushll v7.2d, v5.2s, #0"),
    # USHR (vector shift right)
    ("0x6f100407", "ushr v7.8h, v0.8h"),
    # SSRA
    ("0x0f201447", "ssra"),
    # FDOT by-element: source should be .8b/.2b
    ("0x0f4800f0", "fdot v16.4h, v7.8b, v8.2b[0]"),
    # SDOT by-element: source should be .16b/.4b
    ("0x4f82e95d", "sdot v29.4s, v10.16b, v2.4b[2]"),
    # UDOT by-element
    ("0x6f82e95d", "udot v29.4s, v10.16b, v2.4b[2]"),
    # SVE2 widening: SMLSLB destination wider, sources narrow
    ("0x44535350", "smlslb z16.h, z26.b, z19.b"),
    # DUP vector element
    ("0x4e0804e7", "dup v7.2d, v7.d[0]"),
    # TBX with byte arrangement
    ("0x4e0811a1", "tbx v1.16b, { v13.16b }, v8.16b"),
]

def main():
    passed = 0
    failed = 0
    for hex_enc, expected in TESTS:
        result = subprocess.run([DISASM, hex_enc], capture_output=True, text=True)
        output = result.stdout.strip()
        # Remove hex prefix from output
        if ':' in output:
            output = output.split(':', 1)[1].strip()
        if expected in output:
            passed += 1
        else:
            failed += 1
            print(f"FAIL: {hex_enc}")
            print(f"  Expected substring: {expected}")
            print(f"  Got: {output}")

    print(f"\n{passed}/{passed+failed} tests passed")
    if failed:
        print(f"FAILED: {failed} test(s)")
        return 1
    return 0

if __name__ == '__main__':
    sys.exit(main())

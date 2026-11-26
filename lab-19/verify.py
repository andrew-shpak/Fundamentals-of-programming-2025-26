#!/usr/bin/env python3
"""Compile the ten standalone exercises and compare their exact output."""

import json
import os
from pathlib import Path
import shlex
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent


def run(command, **kwargs):
    result = subprocess.run(
        command, text=True, capture_output=True, timeout=60, **kwargs
    )
    if result.returncode:
        raise AssertionError(
            f"Command failed: {shlex.join(command)}\n{result.stdout}{result.stderr}"
        )
    return result.stdout


def main():
    cases = json.loads((ROOT / "cases.json").read_text(encoding="utf-8"))
    sources = {path.name for path in (ROOT / "src").glob("*.cpp")}
    assert len(cases) == 10 and len(sources) == 10
    assert sources == {case["source"] for case in cases}
    compiler = shlex.split(os.environ.get("CXX", "c++"))
    flags = [
        "-std=c++20", "-Wall", "-Wextra", "-Werror", "-pedantic",
        "-fsanitize=address,undefined", "-fno-sanitize-recover=all",
        "-fno-omit-frame-pointer",
    ]
    checks = 0
    with tempfile.TemporaryDirectory(prefix="lab19-") as directory:
        for case in cases:
            source = ROOT / "src" / case["source"]
            binary = str(Path(directory) / source.stem)
            run(compiler + flags + [str(source), "-o", binary])
            for test in case["tests"]:
                actual = run([binary], input=test["input"])
                assert actual == test["expected"], (
                    f'{source.name} ({test["name"]}):\n'
                    f'expected={test["expected"]!r}\nactual={actual!r}'
                )
                checks += 1
    print(f"PASS: {len(cases)} programs, {checks} cases (ASan/UBSan)")


if __name__ == "__main__":
    main()

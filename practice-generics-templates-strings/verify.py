#!/usr/bin/env python3
"""Compile standalone C++ exercises and check their public contracts."""

import argparse
import json
import os
from pathlib import Path
import re
import shlex
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent


def run(command, **kwargs):
    result = subprocess.run(command, text=True, capture_output=True, timeout=60, **kwargs)
    if result.returncode:
        raise AssertionError(
            f"Command failed: {shlex.join(map(str, command))}\n{result.stdout}{result.stderr}"
        )
    return result.stdout


def check_output(binary, input_text, expected):
    actual = run([str(binary)], input=input_text)
    if actual != expected:
        raise AssertionError(f"{binary.name}: input={input_text!r}\nexpected={expected!r}\nactual={actual!r}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--no-sanitizers', action='store_true')
    args = parser.parse_args()
    compiler = shlex.split(os.environ.get('CXX', 'c++'))
    flags = ['-std=c++20', '-Wall', '-Wextra', '-Werror', '-pedantic', '-g']
    if not args.no_sanitizers:
        flags += ['-fsanitize=address,undefined', '-fno-sanitize-recover=all', '-fno-omit-frame-pointer']
    cases = json.loads((ROOT / 'cases.json').read_text())
    discovered = {str(path.relative_to(ROOT)) for path in ROOT.glob('*/src/*.cpp')}
    assert set(cases) == discovered, 'Each source must have test cases'
    checks = 0
    builds = 0

    # Test actual documented examples, not an independent copy of their text.
    for section in ('generics', 'templates', 'strings'):
        paths = sorted((ROOT / section / 'src').glob('*.cpp'))
        assert len(paths) == 10, f'{section} must contain exactly 10 tasks'
        readme = (ROOT / section / 'Readme.md').read_text()
        assert len(re.findall(r'^### Завдання \d+ —', readme, re.M)) == 10
        for path in paths:
            sample_input, sample_output = cases[str(path.relative_to(ROOT))][0]
            sample = (path.parent.parent / 'samples' / (path.stem + '.txt')).read_text()
            assert f'Ввід:\n{sample_input}\nВивід:\n{sample_output}' in sample
            assert f'Ввід:\n```text\n{sample_input}```\nВивід:\n```text\n{sample_output}```' in readme
        for match in re.finditer(r'\]\(([^)#]+)(?:#[^)]*)?\)', readme):
            assert (ROOT / section / match[1]).exists(), f'Broken link: {match[1]}'

    with tempfile.TemporaryDirectory(prefix='cpp-workbook-') as temporary:
        folder = Path(temporary)

        def compile_source(source, name):
            nonlocal builds
            binary = folder / name
            run(compiler + flags + [str(source), '-o', str(binary)])
            builds += 1
            return binary

        for relative, examples in cases.items():
            binary = compile_source(ROOT / relative, relative.replace('/', '_')[:-4])
            for input_text, expected in examples:
                check_output(binary, input_text, expected)
                checks += 1

            if relative.startswith('strings/'):
                # All readers enforce their common length/ASCII contract.
                for bad in ('x' * 1001 + '\n', '\t\n', 'ї\n', ''):
                    check_output(binary, bad, 'Некоректні дані\n')
                    checks += 1
            if relative.startswith('generics/') and 'task01_' not in relative:
                for bad in ('101\n', '-1\n', '1\n1001\n'):
                    check_output(binary, bad, 'Некоректні дані\n')
                    checks += 1

        double_examples = [
            ('1.5 -2.25\n', '-2.25 1.5\n'),
            ('3\n1.5 -2.25 0.5\n', '-2.25 1.5\n'),
            ('3\n1.5 -2.25 0.5\n', '-0.25\n'),
            ('3\n1.5 -2.25 1.5\n1.5\n', '0\n'),
            ('3\n1.5 -2.25 1.5\n1.5\n', '2\n'),
            ('3\n1.5 -2.25 0.5\n', '0.5 -2.25 1.5\n'),
            ('3\n-2.25 0.5 1.5\n', 'Так\n'),
            ('3\n1.5 -2.25 0.5\n', '-2.25 0.5 1.5\n'),
            ('3\n1.5 -2.25 1.5\n', '1.5 -2.25\n'),
            ('2\n-2.25 1.5\n2\n0.5 1.5\n', '-2.25 0.5 1.5 1.5\n'),
        ]
        for path, example in zip(sorted((ROOT / 'generics/src').glob('*.cpp')), double_examples):
            source = folder / path.name
            source.write_text(path.read_text().replace('using Value = int;', 'using Value = double;'))
            binary = compile_source(source, 'double_' + path.stem)
            check_output(binary, *example)
            checks += 1

        # Compile the same types with different parameters and exercise their APIs directly.
        api_checks = [
            'Box<std::string> b("a"); b.Set("b"); const auto& c = b; assert(c.Get() == "b");',
            'Pair<int, double> p{7, 2.5}; assert(p.first == 7 && p.second == 2.5);',
            '''FixedArray<double, 2> a; a.At(0) = 1.5; const auto& c = a;
               assert(c.At(0) == 1.5); bool caught = false;
               try { (void)c.At(2); } catch (const std::out_of_range&) { caught = true; }
               assert(caught);''',
            '''Stack<std::string, 2> s; std::string result = "unchanged";
               assert(!s.Pop(result) && result == "unchanged" && s.Size() == 0);
               assert(s.Push("a") && s.Push("b") && !s.Push("c") && s.Size() == 2);
               assert(s.Pop(result) && result == "b");
               assert(s.Pop(result) && result == "a");
               assert(!s.Pop(result) && result == "a");''',
            '''Queue<double, 2> q; double result = 99.5;
               assert(!q.Pop(result) && result == 99.5);
               for (int i = 0; i < 20; ++i) {
                   assert(q.Push(i + 0.5) && q.Push(i + 1.5) && !q.Push(999.5));
                   assert(q.Pop(result) && result == i + 0.5);
                   assert(q.Pop(result) && result == i + 1.5 && q.Size() == 0);
               }
               Queue<int, 1> one; int n = 0;
               assert(one.Push(7) && !one.Push(8) && one.Pop(n) && n == 7);''',
            '''Statistics<double> s; double low = 10, high = 20;
               assert(!s.MinMax(low, high) && low == 10 && high == 20);
               s.Add(-2.5); s.Add(0.5);
               assert(s.Count() == 2 && s.Sum() == -2 && s.MinMax(low, high));
               assert(low == -2.5 && high == 0.5);''',
            '''Dictionary<int, std::string, 2> d; std::string result = "unchanged";
               assert(!d.TryGet(1, result) && result == "unchanged");
               assert(d.Set(1, "a") && d.Set(2, "b") && !d.Set(3, "c"));
               assert(d.Set(1, "updated") && d.TryGet(1, result) && result == "updated");
               assert(!d.TryGet(3, result) && result == "updated");''',
            '''Matrix<double, 1, 3> m; m.data[0][0] = 0.5; m.data[0][2] = 2.5;
               auto t = m.Transpose(); auto original = t.Transpose();
               assert(t.data[0][0] == 0.5 && t.data[2][0] == 2.5);
               assert(original.data[0][2] == 2.5 && m.data[0][2] == 2.5);''',
            '''struct AddHalf { double operator()(double n) const { return n + 0.5; } };
               double a[]{1.0, 2.0}; Transformer<double, AddHalf>::Apply(a, 2, AddHalf{});
               assert(a[0] == 1.5 && a[1] == 2.5);''',
            'Formatter<std::string>::Print("text"); Formatter<bool>::Print(false);',
        ]
        for path, body in zip(sorted((ROOT / 'templates/src').glob('*.cpp')), api_checks):
            source = folder / ('api_' + path.name)
            prefix = path.read_text().split('int main() {', 1)[0]
            source.write_text('#include <cassert>\n#include <string>\n' + prefix + '\nint main() {\n' + body + '\n}\n')
            binary = compile_source(source, 'api_' + path.stem)
            check_output(binary, '', 'text\nНі\n' if 'task10_' in path.name else '')
            checks += 1

    print(f'PASS: 30 tasks, {builds} builds, {checks} runtime checks; documentation and samples match.')
    print('Sanitizers: ' + ('disabled' if args.no_sanitizers else 'AddressSanitizer + UndefinedBehaviorSanitizer'))


if __name__ == '__main__':
    main()

# Solve 2026-06-16

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
s = 0

for _ in range(n):
    x = filter(lambda c: c != ',', list(input()))
    x = int(''.join(x))
    s += x

print(f'{s:,}')

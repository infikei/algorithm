# Solve 2026-02-12

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())

print(1 if n == 1 else n * 2 - 2)

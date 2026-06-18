# Solve 2026-06-17

import sys

input = lambda: sys.stdin.readline().rstrip()

a, b = input().split()
a = sum(map(int, list(a)))
b = sum(map(int, list(b)))
print(a * b)


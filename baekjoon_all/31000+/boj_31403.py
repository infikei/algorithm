# Solve 2025-07-20

import sys

input = lambda: sys.stdin.readline().rstrip()

a, b, c = [input() for _ in range(3)]
print(int(a) + int(b) - int(c))
print(int(a + b) - int(c))

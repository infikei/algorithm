# Solve 2025-10-30

import sys

input = lambda: sys.stdin.readline().rstrip()

h = int(input())

while h % 8 not in [0, 5]:
    h += 1

print(h)

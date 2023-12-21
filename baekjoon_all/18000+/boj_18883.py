# Solve 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())

for i in range(1, n * m + 1, m):
    print(*range(i, i + m))

# Solve 2025-09-30

import sys

input = lambda: sys.stdin.readline().rstrip()

e, f, c = map(int, input().split())
cnt = (e + f - 1) // (c - 1)
cnt = max(cnt, 0)
print(cnt)

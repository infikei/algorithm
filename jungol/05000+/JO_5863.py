# Solve 2026-06-13

import sys

input = lambda: sys.stdin.readline().rstrip()

a, b = map(int, input().split())
ans = []

for x in range(-2000, 2001):
    if x * x + 2 * a * x + b == 0:
        ans.append(x)

print(*ans)

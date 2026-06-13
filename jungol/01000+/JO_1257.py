# Solve 2026-06-10

import sys
from bisect import bisect_left

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
lines = [list(map(int, input().split())) for _ in range(n)]
lines.sort()

prv = [-1] * n
memo = []

for i in range(n):
    a, b = lines[i]
    idx = bisect_left(memo, [b, i])

    if idx == len(memo):
        memo.append([b, i])
    else:
        memo[idx] = [b, i]

    if idx >= 1:
        prv[i] = memo[idx - 1][1]

selected = [False] * n
last = memo[-1][1]

while last > -1:
    selected[last] = True
    last = prv[last]

print(n - len(memo))

for i in range(n):
    if not selected[i]:
        print(lines[i][0])

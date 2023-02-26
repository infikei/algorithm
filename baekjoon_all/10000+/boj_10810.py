# Solve 2023-02-23
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
li = [0] * (n + 1)

for _ in range(m):
    i, j, k = map(int, input().split())
    for idx in range(i, j + 1):
        li[idx] = k

print(*li[1:])

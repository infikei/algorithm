# Solve 2023-02-23
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
li = [i for i in range(n + 1)]

for _ in range(m):
    i, j = map(int, input().split())
    li[i], li[j] = li[j], li[i]

print(*li[1:])

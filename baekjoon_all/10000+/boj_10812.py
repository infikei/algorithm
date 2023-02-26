# Solve 2023-02-24
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
li = [i for i in range(n + 1)]

for _ in range(m):
    left, right, mid = map(int, input().split())
    li[left:right + 1] = li[mid:right + 1] + li[left:mid]

print(*li[1:])

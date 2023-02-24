# Solve 2023-02-24

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
li = [i for i in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    li[a:b + 1] = reversed(li[a:b + 1])

print(*li[1:])

# Solve 2023-03-04
# Update 2023-09-06

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
li = [0] + list(map(int, input().split()))

for i in range(1, n + 1):
    li[i] += li[i - 1]

for _ in range(m):
    s, e = map(int, input().split())

    print(li[e] - li[s - 1])

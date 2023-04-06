# Solve 2023-04-05

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    print("%d %d" % (m * 2 - n, n - m))

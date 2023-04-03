# Solve 2023-04-02

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())
for _ in range(t):
    print(sum(map(int, input().split())))

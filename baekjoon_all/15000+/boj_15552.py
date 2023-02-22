# Solve 2022-05-16
# Update 2023-02-22

import sys

input = sys.stdin.readline

t = int(input())
for ti in range(t):
    print(sum(map(int, input().split())))

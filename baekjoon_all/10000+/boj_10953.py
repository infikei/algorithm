# Solve 2022-05-28
# Update 2023-02-22

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    print(sum(map(int, input().split(","))))

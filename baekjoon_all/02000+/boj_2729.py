# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    print(bin(sum(map(lambda x: int(x, 2), input().split())))[2:])

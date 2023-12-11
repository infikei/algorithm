# Solve 2023-03-23
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    print(sum(map(int, input().split())))

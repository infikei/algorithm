# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = sorted(set(map(int, input().split())))
print(*li)

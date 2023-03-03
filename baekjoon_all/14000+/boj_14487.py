# Solve 2023-03-03

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
v = list(map(int, input().split()))

print(sum(v) - max(v))

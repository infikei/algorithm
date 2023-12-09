# Solve 2023-12-09

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
s = sum(map(int, input().split()))

print(min(s, n - s))

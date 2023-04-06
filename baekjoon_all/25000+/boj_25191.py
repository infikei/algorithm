# Solve 2023-04-05

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
a, b = map(int, input().split())

print(min(n, a // 2 + b))

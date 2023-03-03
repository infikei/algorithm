# Solve 2023-03-03

import sys

input = lambda : sys.stdin.readline().rstrip()

a, b = map(int, input().split())
c = int(input())

a += b
if a < c * 2:
    print(a)
else:
    print(a - c * 2)

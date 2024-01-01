# Solve 2023-12-30

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    e, n = map(int, input().split())
    li = [int(input()) for _ in range(n)]
    print(sum([1 if x > e else 0 for x in li]))

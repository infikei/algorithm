# Solve 2022-05-30
# Update 2023-03-03

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = [tuple(map(int, input().split())) for _ in range(n)]

for i in sorted(li):
    print(*i)

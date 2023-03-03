# Solve 2022-06-01
# Update 2023-03-03

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = [tuple(reversed(list(map(int, input().split())))) for _ in range(n)]

for i in sorted(li):
    print(i[1], i[0])

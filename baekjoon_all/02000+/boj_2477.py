# Solve 2023-03-15

import sys

input = lambda : sys.stdin.readline().rstrip()

k = int(input())
pt = [list(map(int, input().split())) for _ in range(6)]

key = 0
for i in range(6):
    if pt[i][0] == pt[i - 4][0] and pt[i - 5][0] == pt[i - 3][0]:
        key = i

area = pt[key - 2][1] * pt[key - 1][1] - pt[key - 5][1] * pt[key - 4][1]

print(area * k)

# Solve 2023-03-22
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

x_min = y_min = 10000
x_max = y_max = -10000

for i in range(n):
    x, y = map(int, input().split())

    x_min = min(x_min, x)
    x_max = max(x_max, x)
    y_min = min(y_min, y)
    y_max = max(y_max, y)

print((x_max - x_min) * (y_max - y_min))

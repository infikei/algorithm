# Solve 2023-03-22

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

x_min, y_min = map(int, input().split())
x_max = x_min
y_max = y_min

for i in range(1, n):
    x, y = map(int, input().split())
    x_min = min(x_min, x)
    x_max = max(x_max, x)
    y_min = min(y_min, y)
    y_max = max(y_max, y)

print((x_max - x_min) * (y_max - y_min))

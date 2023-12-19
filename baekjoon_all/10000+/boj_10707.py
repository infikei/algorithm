# Solve 2023-03-07
# Update 2023-12-19

import sys

input = lambda : sys.stdin.readline().rstrip()

a, b, c, d, p = (int(input()) for _ in range(5))
x_cost = a * p
y_cost = b + max(0, p - c) * d
print(min(x_cost, y_cost))

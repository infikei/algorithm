# Solve 2023-03-10

import sys

input = lambda : sys.stdin.readline().rstrip()

def calc_gcd(a, b):
    if a % b == 0:
        return b
    return calc_gcd(b, a % b)

n = int(input())

x0 = int(input())
x1 = int(input())
x_gcd = abs(x1 - x0)
x_min = min(x0, x1)
x_max = max(x0, x1)

for _ in range(n - 2):
    x1 = int(input())
    x_gcd = calc_gcd(abs(x1 - x0), x_gcd)
    x_min = min(x_min, x1)
    x_max = max(x_max, x1)

print((x_max - x_min) // x_gcd + 1 - n)

# Solve 2023-03-10

import sys

input = lambda : sys.stdin.readline().rstrip()

def calc_gcd(a, b):
    if a % b == 0:
        return b
    return calc_gcd(b, a % b)

a, b = map(int, input().split())
c, d = map(int, input().split())

ans1 = a * d + b * c
ans2 = b * d
gcd = calc_gcd(ans1, ans2)

print(ans1 // gcd, ans2 // gcd)

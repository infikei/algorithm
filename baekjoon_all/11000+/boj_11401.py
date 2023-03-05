# Solve 2023-03-05

import sys

input = lambda : sys.stdin.readline().rstrip()

MOD = 1000000007

def calc_factorial(k):
    res = 1
    for i in range(2, k + 1):
        res *= i
        res %= MOD
    return res

def power(a, b):
    res = 1
    while b > 0:
        if b % 2 == 1:
            res *= a
            res %= MOD
        a *= a
        a %= MOD
        b >>= 1
    return res

n, k = map(int, input().split())

a = calc_factorial(n)
b = calc_factorial(n - k) * calc_factorial(k) % MOD
ans = a * power(b, MOD - 2) % MOD
print(ans)

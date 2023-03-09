# Solve 2023-03-04
# Update 2023-03-08

import sys

input = lambda : sys.stdin.readline().rstrip()

MOD = 1000000007

def calc_power(a, b):
    res = 1
    while b > 0:
        if b % 2 == 1:
            res *= a
            res %= MOD
        a *= a
        a %= MOD
        b >>= 1
    return res

m = int(input())
ans = 0

for _ in range(m):
    n, s = map(int, input().split())
    ans += s * calc_power(n, MOD - 2) % MOD
    ans %= MOD

print(ans)

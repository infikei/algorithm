# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

MOD = 1000000007

def pow(a, b):
    if b == 1:
        return a
    res = pow(a, b // 2)
    res = res * res % MOD
    if b % 2 == 1:
        res = res * a % MOD
    return res

m = int(input())
ans = 0

for _ in range(m):
    n, s = map(int, input().split())
    ans = (s * pow(n, MOD - 2) % MOD + ans) % MOD

print(ans)

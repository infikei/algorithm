# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

MOD = pow(10, 9)
n = int(input())

dp = [[0] + [1] * 9 for _ in range(n)]
for i in range(1, n):
    dp[i][0] = dp[i - 1][1]
    dp[i][9] = dp[i - 1][8]
    for j in range(1, 9):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD

print(sum(dp[n - 1]) % MOD)

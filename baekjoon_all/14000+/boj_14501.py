# Solve 2023-03-03

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
t = [list(map(int, input().split())) for _ in range(n)]
t, p = map(list, zip(*t))

ans = 0
dp = [0] * (n + 1)
for i in range(n - 1, -1, -1):
    for j in range(i + t[i], n + 1):
        dp[i] = max(dp[i], p[i] + dp[j])
    ans = max(ans, dp[i])

print(ans)

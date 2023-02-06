n = int(input())
dp = [0 for _ in range(n+1)]
for i in range(2, n+1):
    dp[i] = dp[i-1]*2 - (i%2)*2 + 1
print(dp[n])
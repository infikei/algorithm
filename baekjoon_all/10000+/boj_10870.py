# Solve 2022-05-25
# Update 2023-03-03

n = int(input())

dp = [0] * 21
dp[1] = 1
for i in range(2, n + 1):
    dp[i] = dp[i - 2] + dp[i - 1]

print(dp[n])

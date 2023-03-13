# Solve 2022-08-05
# Update 2023-03-13

n = int(input())
dp = [0] * max(3, (n + 1))
dp[2] = 1

for i in range(3, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2] * 2

print(dp[n])

# Solve 2022-05-26
# Update 2023-03-23

dp = [0, 1, 2, 4]
for i in range(4, 11):
    dp.append(dp[i - 3] + dp[i - 2] + dp[i - 1])

t = int(input())

for _ in range(t):
    n = int(input())
    print(dp[n])

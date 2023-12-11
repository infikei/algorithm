# Solve 2022-05-26
# Update 2023-12-11

dp = [0, 1, 2, 4]

for i in range(4, 11):
    dp.append(dp[i - 3] + dp[i - 2] + dp[i - 1])

for _ in range(int(input())):
    n = int(input())
    print(dp[n])

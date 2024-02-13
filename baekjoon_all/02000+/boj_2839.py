# Solve 2022-05-21
# Update 2024-02-13

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
dp = [0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4]
print(-1 if n == 4 or n == 7 else n // 15 * 3 + dp[n % 15])

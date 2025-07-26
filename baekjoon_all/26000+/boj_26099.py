# Solve 2025-07-26

import sys

input = lambda : sys.stdin.readline().rstrip()

memo = [0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4]
n = int(input())
print(-1 if n == 4 or n == 7 else n // 15 * 3 + memo[n % 15])

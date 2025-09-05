# Solve 2022-05-21
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

memo = [0, 1, 2, 1, 2, 1, 2, 3, 2, 3, 2, 3, 4, 3, 4]
n = int(input())
print(-1 if n in [4, 7] else n // 15 * 3 + memo[n % 15])

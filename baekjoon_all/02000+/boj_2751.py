# Solve 2022-06-01
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

nums = [int(input()) for _ in range(int(input()))]
nums.sort()
print(*nums, sep="\n")

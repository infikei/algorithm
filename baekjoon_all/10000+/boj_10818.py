# Solve 2022-05-16
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
nums = list(map(int, input().split()))

print(min(nums), max(nums))

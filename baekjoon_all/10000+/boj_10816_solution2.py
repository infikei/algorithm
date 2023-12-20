# Solve 2023-10-09
# Update 2023-12-20

import sys
from bisect import bisect_left, bisect_right

input = lambda : sys.stdin.readline().rstrip()

_ = input()
nums = sorted(map(int, input().split()))
_ = input()
queries = map(int, input().split())
answers = map(lambda x: bisect_right(nums, x) - bisect_left(nums, x), queries)

print(*answers)

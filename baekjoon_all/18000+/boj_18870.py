# Solve 2022-06-01
# Update 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

_ = input()
nums = list(map(int, input().split()))
sorted_unique_nums = sorted(set(nums))
dic = {sorted_unique_nums[i]: i for i in range(len(sorted_unique_nums))}

print(*[dic[num] for num in nums])

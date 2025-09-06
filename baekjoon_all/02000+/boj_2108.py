# Solve 2022-05-28
# Update 2025-09-05

import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()

def round(x):
    sign = -1 if x < 0 else 1
    x = abs(x)

    if x - int(x) >= 0.5:
        return sign * (int(x) + 1)
    else:
        return sign * int(x)


def avg(nums):
    return sum(nums) / len(nums)


def median(nums):
    return nums[len(nums) // 2]


def mode(nums):
    counter = Counter(nums)
    res = counter.most_common(2)

    if len(res) >= 2 and res[0][1] == res[1][1]:
        return res[1][0]
    else:
        return res[0][0]


nums = [int(input()) for _ in range(int(input()))]
nums.sort()

print(round(avg(nums)))
print(median(nums))
print(mode(nums))
print(nums[-1] - nums[0])

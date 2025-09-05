# Solve 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

def round(num):
    if num - int(num) >= 0.5:
        return int(num) + 1
    else:
        return int(num)


def avg(nums):
    return sum(nums) / len(nums)


def solution():
    if (n := int(input())) == 0:
        print(0)
        return

    tiers = sorted(int(input()) for _ in range(n))
    n_exclude = round(n * 0.15)
    tier = round(avg(tiers[n_exclude:n - n_exclude]))
    print(tier)


solution()

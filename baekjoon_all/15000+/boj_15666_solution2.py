# Solve 2025-09-25

import sys
from itertools import combinations_with_replacement

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
nums = sorted(set(map(int, input().split())))

for selected_nums in combinations_with_replacement(nums, m):
    print(*selected_nums)

# Solve 2025-09-25

import sys
from itertools import permutations

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
nums = sorted(map(int, input().split()))
memo = set()

for selected_nums in permutations(nums, m):
    if selected_nums not in memo:
        print(*selected_nums)
        memo.add(selected_nums)

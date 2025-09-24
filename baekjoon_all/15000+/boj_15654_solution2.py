# Solve 2025-09-23

import sys
from itertools import permutations

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
nums = sorted(map(int, input().split()))

for selected_nums in permutations(nums, m):
    print(*selected_nums)

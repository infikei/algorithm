# Solve 2025-09-25

import sys

input = lambda: sys.stdin.readline().rstrip()

def recur(depth: int, max_depth: int, start_index: int, nums: list[int], selected_nums: list[int]):
    if depth == max_depth:
        print(*selected_nums)
        return

    for i in range(start_index, len(nums)):
        selected_nums[depth] = nums[i]
        recur(depth + 1, max_depth, i, nums, selected_nums)


n, m = map(int, input().split())
nums = sorted(set(map(int, input().split())))
recur(0, m, 0, nums, [-1] * m)

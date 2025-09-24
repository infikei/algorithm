# Solve 2025-09-23

import sys

input = lambda: sys.stdin.readline().rstrip()

def recur(max_depth: int, nums: list[int], selected_nums: list[int], selected: list[bool]):
    if len(selected_nums) == max_depth:
        print(*selected_nums)
        return

    for i in range(len(nums)):
        if not selected[i]:
            selected[i] = True
            selected_nums.append(nums[i])
            recur(max_depth, nums, selected_nums, selected)
            selected_nums.pop()
            selected[i] = False


n, m = map(int, input().split())
nums = sorted(map(int, input().split()))
recur(m, nums, [], [False] * n)

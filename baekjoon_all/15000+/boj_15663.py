# Solve 2025-09-25

import sys

input = lambda: sys.stdin.readline().rstrip()

def recur(depth: int, max_depth: int, nums: list[int], selected_nums: list[int], selected: list[bool]):
    if depth == max_depth:
        print(*selected_nums)
        return

    for i in range(len(nums)):
        if selected[i] or selected_nums[depth] == nums[i]:
            continue

        selected[i] = True
        selected_nums[depth] = nums[i]
        recur(depth + 1, max_depth, nums, selected_nums, selected)
        selected[i] = False

    selected_nums[depth] = -1


n, m = map(int, input().split())
nums = sorted(map(int, input().split()))
recur(0, m, nums, [-1] * m, [False] * n)

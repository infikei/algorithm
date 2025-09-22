# Solve 2022-05-29
# Update 2025-09-22

import sys

input = lambda: sys.stdin.readline().rstrip()

def recur(max_depth: int, end_num: int, nums: list[int], selected: list[bool]):
    if max_depth == len(nums):
        print(*nums)
        return

    for i in range(1, end_num + 1):
        if not selected[i]:
            selected[i] = True
            nums.append(i)
            recur(max_depth, end_num, nums, selected)
            nums.pop()
            selected[i] = False


n, m = map(int, input().split())
recur(m, n, [], [False] * (n + 1))

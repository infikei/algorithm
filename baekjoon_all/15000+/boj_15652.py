# Solve 2022-05-29
# Update 2025-09-22

import sys

input = lambda: sys.stdin.readline().rstrip()

def recur(max_n_nums: int, start_num: int, end_num: int, nums: list[int]):
    if len(nums) == max_n_nums:
        print(*nums)
        return

    for i in range(start_num, end_num + 1):
        nums.append(i)
        recur(max_n_nums, i, end_num, nums)
        nums.pop()


n, m = map(int, input().split())
recur(m, 1, n, [])

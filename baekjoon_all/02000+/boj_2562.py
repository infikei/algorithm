# Solve 2022-05-19
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

max_num = max_idx = 0

for i in range(1, 10):
    num = int(input())

    if num > max_num:
        max_num = num
        max_idx = i

print(max_num, max_idx, sep="\n")

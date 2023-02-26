# Solve 2022-05-19
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

max_val = max_idx = 0

for idx in range(1, 10):
    x = int(input())
    if x > max_val:
        max_val = x
        max_idx = idx

print(max_val)
print(max_idx)

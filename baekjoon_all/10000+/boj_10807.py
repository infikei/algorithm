# Solve 2023-02-23
# Update 2023-12-19

import sys

input = lambda : sys.stdin.readline().rstrip()

n = input()
nums = input().split()
v = input()

print(len(list(filter(lambda x: x == v, nums))))

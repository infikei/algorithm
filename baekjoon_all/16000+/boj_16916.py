# Solve 2023-03-12
# Update 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

s = input()
p = input()

print([0, 1][p in s])

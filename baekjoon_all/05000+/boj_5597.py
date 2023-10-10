# Solve 2023-02-23
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

nums = set(range(1, 31)) - set([int(input()) for _ in range(28)])

print(*sorted(nums), sep="\n")

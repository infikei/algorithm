# Solve 2023-02-23
# Update 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

st = set(range(1, 31)) - set([int(input()) for _ in range(28)])

print(*sorted(list(st)), sep="\n")

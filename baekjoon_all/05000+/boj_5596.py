# Solve 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

print(max([sum(map(int, input().split())) for _ in range(2)]))

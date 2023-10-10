# Solve 2022-05-16
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for ti in range(1, t + 1):
    print(f"Case #{ti}: {sum(map(int, input().split()))}")

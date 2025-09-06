# Solve 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

_ = int(input())
numbers = set(map(int, input().split()))
_ = int(input())

for x in map(int, input().split()):
    print(1 if x in numbers else 0)

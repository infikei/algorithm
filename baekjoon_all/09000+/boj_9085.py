# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n = int(input())
    numbers = list(map(int, input().split()))
    print(sum(numbers))

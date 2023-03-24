# Solve 2023-03-24

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())
li = [int(input()) for _ in range(t)]
for i in li:
    print("=" * i)

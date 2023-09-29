# Solve 2023-09-29

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(3):
    n = int(input())
    ans = sum([int(input()) for _ in range(n)])

    if ans > 0:
        print("+")
    elif ans < 0:
        print("-")
    else:
        print("0")

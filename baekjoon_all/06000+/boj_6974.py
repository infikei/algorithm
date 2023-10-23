# Solve 2023-10-22

import sys

input = lambda : sys.stdin.readline().rstrip()

for ti in range(int(input())):
    if ti >= 1:
        print()

    a, b = int(input()), int(input())

    print(a // b)
    print(a % b)

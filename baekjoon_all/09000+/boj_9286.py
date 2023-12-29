# Solve 2023-12-28

import sys

input = lambda : sys.stdin.readline().rstrip()

for ti in range(1, int(input()) + 1):
    print(f"Case {ti}:")
    n = int(input())
    students = [int(input()) + 1 for _ in range(n)]

    for i in students:
        if i != 7:
            print(i)

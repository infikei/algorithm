# Solve 2023-03-26

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(3):
    val = sum(map(int, input().split()))
    if val == 0:
        print("D")
    elif val == 1:
        print("C")
    elif val == 2:
        print("B")
    elif val == 3:
        print("A")
    else:
        print("E")

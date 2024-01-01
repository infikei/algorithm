# Solve 2023-12-30

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    _ = input()
    w_sum = sum(map(int, input().split()))

    if w_sum > 0:
        print("Right")
    elif w_sum < 0:
        print("Left")
    else:
        print("Equilibrium")

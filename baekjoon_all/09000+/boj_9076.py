# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    scores = list(sorted(map(int, input().split())))
    if scores[3] - scores[1] >= 4:
        print("KIN")
    else:
        print(sum(scores[1:4]))

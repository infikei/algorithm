# Solve 2023-03-23
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    scores = sorted(map(int, input().split()))

    if scores[3] - scores[1] >= 4:
        print("KIN")
    else:
        print(sum(scores[1:4]))

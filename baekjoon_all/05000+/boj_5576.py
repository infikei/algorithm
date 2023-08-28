# Solve 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(2):
    scores = [int(input()) for _ in range(10)]

    print(sum(sorted(scores, reverse=True)[0:3]), end=" ")

# Solve 2022-05-19
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    oxox = input()
    score = cumulative = 0

    for ch in oxox:
        if ch == "O":
            cumulative += 1
            score += cumulative
        else:
            cumulative = 0

    print(score)

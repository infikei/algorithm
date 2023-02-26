# Solve 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

serolines = [""] * 15
for _ in range(5):
    line = input()
    for j in range(len(line)):
        serolines[j] += line[j]

print(*serolines, sep="")

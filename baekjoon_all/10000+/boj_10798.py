# Solve 2023-02-26
# Update 2023-12-19

import sys

input = lambda : sys.stdin.readline().rstrip()

serolines = [""] * 15

for _ in range(5):
    line = input()

    for col in range(len(line)):
        serolines[col] += line[col]

print(*serolines, sep="")

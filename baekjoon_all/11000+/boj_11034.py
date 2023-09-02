# Solve 2023-04-02
# Update 2023-09-02

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    line = input()
    if line == "": break

    a, b, c = map(int, line.split())
    print(max(b - a, c - b) - 1)

# Solve 2023-04-02

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    line = input()
    if line == "":
        break
    a, b, c = map(int, line.split())
    print(max(b - a - 1, c - b - 1))

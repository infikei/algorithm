# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

for _ in range(n):
    line = input().split()
    line = map(lambda word: "".join(reversed(word)), line)
    line = " ".join(line)
    print(line)

# Solve 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    s = input()
    print(s[0] + s[-1])

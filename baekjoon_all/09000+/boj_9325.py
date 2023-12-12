# Solve 2023-12-12

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    s = int(input())

    for _ in range(int(input())):
        q, p = map(int, input().split())
        s += q * p

    print(s)

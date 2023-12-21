# Solve 2023-12-21

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    for _ in range(int(input())):
        a, b = map(int, input().split())
        print(a + b, a * b)

# Solve 2023-04-01

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    n = int(input())
    if n == 0:
        break

    print(n * (n + 1) * (n * 2 + 1) // 6)

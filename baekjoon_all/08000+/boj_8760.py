# Solve 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    w, k = map(int, input().split())

    print(w * k // 2)

# Solve 2026-06-14

import sys

input = lambda: sys.stdin.readline().rstrip()

x = int(input()) * int(input()) * int(input())
x = list(map(int, list(str(x))))

for d in range(10):
    print(x.count(d))

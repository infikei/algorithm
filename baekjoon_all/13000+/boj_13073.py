# Solve 2024-01-21

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    n2 = n * n
    n2_n = n2 + n
    print(f"{n2_n // 2} {n2} {n2_n}")

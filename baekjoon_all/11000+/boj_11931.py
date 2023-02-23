# Solve 2023-02-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = sorted([(int(input())) for _ in range(n)], reverse=True)

print(*li, sep="\n")

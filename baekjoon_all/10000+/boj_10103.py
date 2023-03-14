# Solve 2023-03-14

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
scores = [100] * 2

for _ in range(n):
    x, y = map(int, input().split())
    if x > y:
        scores[1] -= x
    elif x < y:
        scores[0] -= y

print(*scores, sep="\n")

# Solve 2023-03-14
# Update 2023-12-15

import sys

input = lambda : sys.stdin.readline().rstrip()

scores = [100, 100]

for _ in range(int(input())):
    x, y = map(int, input().split())

    if x > y:
        scores[1] -= x
    elif x < y:
        scores[0] -= y

print(*scores, sep="\n")

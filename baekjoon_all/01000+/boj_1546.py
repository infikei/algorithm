# Solve 2022-05-19
# Update 2023-02-24

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
scores = list(map(int, input().split()))

m = sum = 0
for score in scores:
    sum += score
    if score > m:
        m = score

print(sum * 100 / n / m)

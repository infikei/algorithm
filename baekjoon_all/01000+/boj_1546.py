# Solve 2022-05-19
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
scores = list(map(int, input().split()))

max_score = score_sum = 0

for score in scores:
    score_sum += score

    if score > max_score:
        max_score = score

print(score_sum * 100 / n / max_score)

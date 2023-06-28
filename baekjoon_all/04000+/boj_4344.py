# Solve 2022-05-19
# Update 2023-06-27

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    (n, *scores) = list(map(int, input().split()))

    avr_of_scores = sum(scores) / n

    cnt = len(list(filter(lambda x: x > avr_of_scores, scores)))
    ans = round(cnt * 100000 / n) / 1000

    print("%.3f%%" % ans)

# Solve 2022-05-19
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    (n, *scores) = list(map(int, input().split()))

    avr_of_scores = 0
    for score in scores:
        avr_of_scores += score
    avr_of_scores /= n

    ans = 0
    for score in scores:
        if score > avr_of_scores:
            ans += 1
    ans = ans * 100 / n

    print("%.3f%%" % ans)

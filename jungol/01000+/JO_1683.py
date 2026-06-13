# Solve 2026-06-13

import sys

input = lambda: sys.stdin.readline().rstrip()

def solution(n):
    if len(n) % 2:
        n = '0' + n

    li = []

    for i in range(0, len(n), 2):
        li.append(int(n[i:i+2]) % 7)

    if len(li) % 3 == 1:
        li = [0, 0] + li
    elif len(li) % 3 == 2:
        li = [0] + li

    li2 = [0, 0, 0]

    for i in range(0, len(li), 3):
        li2[0] += li[i]
        li2[1] += li[i + 1]
        li2[2] += li[i + 2]

    li2[0] %= 7
    li2[1] %= 7
    li2[2] %= 7

    x = (li2[0] * 10 + li2[1]) % 7
    y = (li2[1] * 10 + li2[2]) % 7

    return (y - x + 7) % 7


for _ in range(3):
    print(solution(input()))

# Solve 2023-10-07

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    n, d = map(int, input().split())

    if n == 0 and d == 0: break

    cnt = [0] * n

    for _ in range(d):
        li = list(map(int, input().split()))

        for ni in range(n):
            cnt[ni] += li[ni]

    ans = False

    for ni in range(n):
        if cnt[ni] == d:
            ans = True
            break

    if ans:
        print("yes")
    else:
        print("no")

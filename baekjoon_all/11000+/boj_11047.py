# Solve 2023-09-02

import sys

input = lambda : sys.stdin.readline().rstrip()

n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
cnt = 0

for coin in coins[::-1]:
    cnt += k // coin
    k %= coin

    if k == 0: break

print(cnt)

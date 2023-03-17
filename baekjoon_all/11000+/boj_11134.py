# Solve 2023-03-17

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n, c = map(int, input().split())
    ans = n // c
    if n % c != 0:
        ans += 1
    print(ans)

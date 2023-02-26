# Solve 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

MAX_N = 1000001
check = [ True ] * MAX_N
check[0] = check[1] = False

for i in range(2, MAX_N):
    if check[i]:
        for j in range(i * 2, MAX_N, i):
            check[j] = False

t = int(input())

for _ in range(t):
    n = int(input())
    ans = 0
    for i in range(2, n // 2 + 1):
        if check[i] and check[n - i]:
            ans += 1
    print(ans)

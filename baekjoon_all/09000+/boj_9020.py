# Solve 2022-05-25
# Update 2025-05-13

import sys

input = lambda: sys.stdin.readline().rstrip()

sieve = [False] + [True] * 10000

for i in range(2, 10001):
    if not sieve[i]:
        continue

    for j in range(i + i, 10001, i):
        sieve[j] = False

for _ in range(int(input())):
    n = int(input())

    for i in range(n // 2, 1, -1):
        if sieve[i] and sieve[n - i]:
            print(i, n - i)
            break

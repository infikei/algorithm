# Solve 2022-05-24
# Update 2023-03-01

import sys

input = lambda : sys.stdin.readline().rstrip()

MAX_SIZE = 1001
primes = [True] * MAX_SIZE
primes[0] = primes[1] = False
for i in range(2, MAX_SIZE):
    if primes[i]:
        for j in range(i + i, MAX_SIZE, i):
            primes[j] = False

n = int(input())
li = list(map(int, input().split()))

ans = 0
for i in li:
    if primes[i]:
        ans += 1

print(ans)

# Solve 2023-12-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = map(int, input().split())
k = 1

for i in li:
    if i == k:
        k += 1

k -= 1

print(n - k)

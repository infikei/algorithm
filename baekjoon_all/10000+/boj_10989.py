# Solve 2022-05-30
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
cnt = [0] * 10001

for _ in range(n):
    cnt[int(input())] += 1

for i in range(1, 10001):
    for j in range(cnt[i]):
        print(i)

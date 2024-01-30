# Solve 2022-05-30
# Update 2024-01-29

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
cnt = [0] * 10001

for _ in range(n):
    cnt[int(input())] += 1

for num in range(1, 10001):
    for _ in range(cnt[num]):
        print(num)

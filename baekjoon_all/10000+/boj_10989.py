# Solve 2022-05-30
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

cnt = [0] * 10001

for _ in range(int(input())):
    cnt[int(input())] += 1

for x in range(10001):
    for _ in range(cnt[x]):
        print(x)

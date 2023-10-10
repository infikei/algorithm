# Solve 2022-05-30
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
num_cnt = [0] * 10001

for _ in range(n):
    num_cnt[int(input())] += 1

for num in range(1, 10001):
    for _ in range(num_cnt[num]):
        print(num)

# Solve 2023-03-15

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
files = list(map(int, input().split()))
size_of_cluster = int(input())
cnt = 0

for file in files:
    cnt += file // size_of_cluster
    if file % size_of_cluster != 0:
        cnt += 1

print(cnt * size_of_cluster)

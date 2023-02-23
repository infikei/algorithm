# Solve 2022-05-16
# Update 2023-02-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = list(map(int, input().split()))
print(min(li), max(li))

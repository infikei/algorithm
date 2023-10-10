# Solve 2022-05-16
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    print(sum(map(int, input().split())))

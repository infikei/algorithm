# Solve 2022-05-28
# Update 2023-12-20

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    print(sum(map(int, input().split(","))))

# Solve 2023-04-02
# Update 2023-09-02

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    print(sum(map(int, input().split())))

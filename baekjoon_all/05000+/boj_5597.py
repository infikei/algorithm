# Solve 2023-02-23
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

li = [0] * 31
for _ in range(28):
    li[int(input())] = 1

for i in range(1, 31):
    if li[i] == 0:
        print(i)

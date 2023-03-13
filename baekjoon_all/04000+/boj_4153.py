# Solve 2022-05-29
# Update 2023-03-13

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    li = list(map(lambda x: int(x) ** 2, input().split()))
    if li[0] == 0:
        break
    li.sort()

    if li[0] + li[1] == li[2]:
        print("right")
    else:
        print("wrong")

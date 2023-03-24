# Solve 2022-05-28
# Update 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    parentheses = input()
    vps = 0
    for par in parentheses:
        if par == "(":
            vps += 1
        else:
            vps -= 1
            if vps < 0:
                break

    if vps == 0:
        print("YES")
    else:
        print("NO")

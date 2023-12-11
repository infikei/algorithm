# Solve 2022-05-28
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
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

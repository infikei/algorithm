# Solve 2022-05-28
# Update 2023-03-20

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    num = input()
    if num == "0":
        break

    ans = True
    for i in range(len(num) // 2):
        if num[i] != num[-1 - i]:
            ans = False
            break
    if ans:
        print("yes")
    else:
        print("no")

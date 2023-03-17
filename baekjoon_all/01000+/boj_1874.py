# Solve 2022-05-31
# Update 2023-03-17

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
stck = []
check = True
ans = []
stck_in_max = 0

for _ in range(n):
    now = int(input())
    while now > stck_in_max:
        stck_in_max += 1
        stck.append(stck_in_max)
        ans.append("+")

    if stck[-1] == now:
        stck.pop()
        ans.append("-")
    else:
        check = False
        break

if check:
    print(*ans, sep="\n")
else:
    print("NO")

# Solve 2026-02-15

import sys
from math import floor

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
li = [int(input())]

for _ in range(n - 1):
    li.append(input())
    li.append(int(input()))

li2 = [li[0]]

for i in range(1, len(li), 2):
    op = li[i]
    num = li[i + 1]

    if op == '*':
        li2[-1] *= num
    elif op == '/':
        li2[-1] //= num
    else:
        li2.append(op)
        li2.append(num)

ans = li2[0]

for i in range(1, len(li2), 2):
    op = li2[i]
    num = li2[i + 1]

    if op == '+':
        ans += num
    else:
        ans -= num

print(ans)

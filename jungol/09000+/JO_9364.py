# Solve 2026-05-18

import sys

input = lambda: sys.stdin.readline().rstrip()

li = input().split()
print(li)

li.append(li[1])
li.append(li[2])
li.append(li[1])
print(li)

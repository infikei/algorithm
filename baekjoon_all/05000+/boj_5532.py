# Solve 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

li = [int(input()) for _ in range(5)]

ko = (li[1] - 1) // li[3] + 1
mt = (li[2] - 1) // li[4] + 1

print(li[0] - max(ko, mt))

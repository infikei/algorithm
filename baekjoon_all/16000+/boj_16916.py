# Solve 2023-03-12

import sys

input = lambda : sys.stdin.readline().rstrip()

s = input()
p = input()

if s.find(p) == -1:
    print(0)
else:
    print(1)

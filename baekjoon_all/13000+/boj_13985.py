# Solve 2023-03-24

import sys

input = lambda : sys.stdin.readline().rstrip()

line = input().split()
if int(line[0]) + int(line[2]) == int(line[4]):
    print("YES")
else:
    print("NO")

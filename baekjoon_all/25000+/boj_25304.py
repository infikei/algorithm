# Solve 2023-02-22
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

x = int(input())
n = int(input())

x2 = 0
for i in range(n):
    a, b = map(int, input().split())
    x2 += a * b

if x == x2:
    print("Yes")
else:
    print("No")

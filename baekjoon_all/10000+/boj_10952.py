# Solve 2022-05-16
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    a, b = map(int, input().split())

    if a == 0 and b == 0: break

    print(a + b)

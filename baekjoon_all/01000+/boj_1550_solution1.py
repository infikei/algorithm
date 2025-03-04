# Solve 2022-05-25
# Update 2025-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

s = input()
n = 0

for ch in s:
    n *= 16

    if ord(ch) >= ord('A'):
        n += ord(ch) - ord('A') + 10
    else:
        n += int(ch)

print(n)

# Solve 2023-03-02

import sys

input = lambda : sys.stdin.readline().rstrip()

n, l = map(int, input().split())
li = sorted(map(int, input().split()))

for i in li:
    if i > l:
        break
    l += 1

print(l)

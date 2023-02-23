# Solve 2023-02-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = list(map(int, input().split()))
v = int(input())
ans = 0

for a in li:
    if a == v:
        ans += 1

print(ans)

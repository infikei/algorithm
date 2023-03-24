# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
cows = [-1] * 11
ans = 0
for i in range(n):
    cow, location = map(int, input().split())
    if cows[cow] == -1:
        cows[cow] = location
    elif cows[cow] != location:
        cows[cow] = location
        ans += 1

print(ans)

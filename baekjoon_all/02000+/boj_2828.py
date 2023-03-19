# Solve 2023-03-18

import sys

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
j = int(input())

ans = 0
left = 1
right = m
for _ in range(j):
    drop = int(input())
    move = 0
    if drop < left:
        move = drop - left
    elif right < drop:
        move = drop - right
    ans += abs(move)
    left += move
    right += move

print(ans)

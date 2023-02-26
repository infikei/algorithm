# Solve 2022-05-19
# Update 2023-02-26

import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    r, s = input().split()
    r = int(r)
    ans = ""
    for ch in s:
        ans += ch * r
    print(ans)

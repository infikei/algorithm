# Solve 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
s = input()
t = input()
ans = True

if n % 2 == 0:
    for i in range(len(s)):
        if s[i] != t[i]:
            ans = False
            break
else:
    for i in range(len(s)):
        if s[i] == t[i]:
            ans = False
            break

if ans:
    print("Deletion succeeded")
else:
    print("Deletion failed")

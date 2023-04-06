# Solve 2023-04-05

import sys

input = lambda : sys.stdin.readline().rstrip()

n, b = map(int, input().split())
ans = ""
s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

while n > 0:
    ans += s[n % b]
    n //= b

print(ans[::-1])

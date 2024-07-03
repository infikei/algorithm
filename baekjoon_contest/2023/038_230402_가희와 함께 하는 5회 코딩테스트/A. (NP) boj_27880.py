# Solve 2023-04-03

import sys

input = lambda : sys.stdin.readline().rstrip()

ans = 0

while True:
    try:
        w, n = input().split()
    except:
        break

    n = int(n)
    if w == "Es":
        ans += n * 21
    else:
        ans += n * 17

print(ans)

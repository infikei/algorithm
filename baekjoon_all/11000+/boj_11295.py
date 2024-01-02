# Solve 2024-01-01

import sys

input = lambda : sys.stdin.readline().rstrip()

user = 0

while True:
    l = int(input())

    if l == 0:
        break

    user += 1
    print(f"User {user}")

    for _ in range(int(input())):
        x = int(input())
        q, r = divmod(l * x, 100000)
        print(f"{q}.{r:05d}")

# Solve 2025-04-27

import sys
input = lambda: sys.stdin.readline().rstrip()

li = [0 for _ in range(21)]

for _ in range(int(input())):
    cmd = input()

    if cmd == "all":
        li = [1 for _ in range(21)]
        continue

    if cmd == "empty":
        li = [0 for _ in range(21)]
        continue

    cmd, x = cmd.split()
    x = int(x)

    if cmd == "add":
        li[x] = 1
    elif cmd == "remove":
        li[x] = 0
    elif cmd == "toggle":
        li[x] = 1 - li[x]
    else:
        print(li[x])

# Solve 2023-03-01

import sys
from collections import deque

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    cmds = input()
    n = int(input())
    nums = input()

    dq = deque()
    if nums != "[]":
        dq = deque(list(map(int, nums.lstrip("[").rstrip("]").split(","))))

    error = False
    reverse = False
    for cmd in cmds:
        if cmd == "D":
            if len(dq) == 0:
                error = True
                break
            if reverse:
                dq.pop()
            else:
                dq.popleft()
        else:
            reverse = not reverse

    if error:
        print("error")
    else:
        if reverse:
            dq.reverse()
        print("[", end="")
        print(*dq, sep=",", end="]\n")

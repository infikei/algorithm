# Solve 2023-03-01

import sys
from collections import deque

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
dq = deque()

for _ in range(n):
    line = input().split()

    if line[0] == "push_front":
        dq.appendleft(line[1])
    elif line[0] == "push_back":
        dq.append(line[1])
    elif line[0] == "pop_front":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.popleft())
    elif line[0] == "pop_back":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.pop())
    elif line[0] == "size":
        print(len(dq))
    elif line[0] == "empty":
        if len(dq) == 0:
            print(1)
        else:
            print(0)
    elif line[0] == "front":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[0])
    else:
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[-1])

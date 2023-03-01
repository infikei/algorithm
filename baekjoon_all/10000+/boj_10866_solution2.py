# Solve 2023-03-01

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
q = []

for _ in range(n):
    line = input().split()

    if line[0] == "push_front":
        q.insert(0, line[1])
    elif line[0] == "push_back":
        q.append(line[1])
    elif line[0] == "pop_front":
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
            del q[0]
    elif line[0] == "pop_back":
        if len(q) == 0:
            print(-1)
        else:
            print(q.pop())
    elif line[0] == "size":
        print(len(q))
    elif line[0] == "empty":
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif line[0] == "front":
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    else:
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])

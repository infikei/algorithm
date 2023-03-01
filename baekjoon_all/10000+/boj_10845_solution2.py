# Solve 2022-06-01
# Update 2023-03-01

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
q = []

for _ in range(n):
    line = input().split()

    if line[0] == "push":
        q.insert(0, line[1])
    elif line[0] == "pop":
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
            print(q[-1])
    else:
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])

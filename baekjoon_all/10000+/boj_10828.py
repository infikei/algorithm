# Solve 2022-06-01
# Update 2023-12-20

import sys

input = lambda : sys.stdin.readline().rstrip()

stack = []

for _ in range(int(input())):
    cmd = input().split()

    if cmd[0] == "push":
        stack.append(cmd[1])
    elif cmd[0] == "pop":
        print(-1 if len(stack) == 0 else stack.pop())
    elif cmd[0] == "size":
        print(len(stack))
    elif cmd[0] == "empty":
        print(1 if len(stack) == 0 else 0)
    elif cmd[0] == "top":
        print(-1 if len(stack) == 0 else stack[-1])

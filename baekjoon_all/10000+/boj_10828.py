# Solve 2022-06-01
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

stack = []

for _ in range(int(input())):
    cmd = input().split()

    match cmd[0]:
        case "push":
            stack.append(cmd[1])
        case "pop":
            print(-1 if len(stack) == 0 else stack.pop())
        case "size":
            print(len(stack))
        case "empty":
            print(1 if len(stack) == 0 else 0)
        case "top":
            print(-1 if len(stack) == 0 else stack[-1])

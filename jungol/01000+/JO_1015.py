# Solve 2026-06-07

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

backward_stack, forward_stack = deque(), deque()
current_page = "http://www.acm.org/"

while True:
    cmd = input().split()

    if cmd[0] == "QUIT":
        break
    elif cmd[0] == "VISIT":
        backward_stack.append(current_page)
        current_page = cmd[1]
        forward_stack.clear()
        print(current_page)
    elif cmd[0] == "BACK":
        if backward_stack:
            forward_stack.appendleft(current_page)
            current_page = backward_stack.pop()
            print(current_page)
        else:
            print("Ignored")
    elif cmd[0] == "FORWARD":
        if forward_stack:
            backward_stack.append(current_page)
            current_page = forward_stack.popleft()
            print(current_page)
        else:
            print("Ignored")

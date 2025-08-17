# Solve 2022-05-31
# Update 2025-08-16

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
stack = []
ans = []
valid_seq = True
max_stack_num = 0

for _ in range(n):
    x = int(input())
    while x > max_stack_num:
        max_stack_num += 1
        stack.append(max_stack_num)
        ans.append("+")

    if stack[-1] == x:
        stack.pop()
        ans.append("-")
    else:
        valid_seq = False
        break

if valid_seq:
    print("\n".join(ans))
else:
    print("NO")

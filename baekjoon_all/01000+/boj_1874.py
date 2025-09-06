# Solve 2022-05-31
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

def solution(li):
    last_num = 0
    stack = []
    operations = []

    for x in li:
        while last_num < x:
            last_num += 1
            stack.append(last_num)
            operations.append("+")

        if stack[-1] != x:
            return "NO"

        stack.pop()
        operations.append("-")

    return "\n".join(operations)


li = [int(input()) for _ in range(int(input()))]
print(solution(li))

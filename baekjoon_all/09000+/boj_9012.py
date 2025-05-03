# Solve 2022-05-28
# Update 2025-05-03

import sys

input = lambda: sys.stdin.readline().rstrip()

def is_valid_parentheses(parentheses: str) -> bool:
    depth = 0

    for par in parentheses:
        if par == '(':
            depth += 1
        else:
            depth -= 1

            if depth < 0:
                return False

    return depth == 0

for _ in range(int(input())):
    parentheses = input()

    if is_valid_parentheses(parentheses):
        print("YES")
    else:
        print("NO")

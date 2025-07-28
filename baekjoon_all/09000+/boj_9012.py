# Solve 2022-05-28
# Update 2025-07-27

import sys

input = lambda: sys.stdin.readline().rstrip()


def is_parentheses_valid(parentheses: str) -> bool:
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
    print("YES" if is_parentheses_valid(input()) else "NO")

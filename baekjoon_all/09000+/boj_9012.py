# Solve 2022-05-28
# Update 2025-09-05

import sys

input = lambda: sys.stdin.readline().rstrip()

def validate_parentheses(ps: str) -> bool:
    depth = 0

    for par in ps:
        if par == "(":
            depth += 1
        else:
            depth -= 1

            if depth < 0:
                return False

    return depth == 0


for _ in range(int(input())):
    ps = input()
    print("YES" if validate_parentheses(ps) else "NO")

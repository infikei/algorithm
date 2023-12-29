# Solve 2023-12-28

import sys

input = lambda : sys.stdin.readline().rstrip()

for ti in range(1, int(input()) + 1):
    first_name = input()
    last_name = input()

    print(f"Case {ti}: {last_name}, {first_name}")

# Solve 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

print(min([int(input()) for _ in range(3)]) + min([int(input()) for _ in range(2)]) - 50)

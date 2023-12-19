# Solve 2023-12-19

import sys

input = lambda : sys.stdin.readline().rstrip()

n = input()
print(len(list(filter(lambda x: x == n, input().split()))))

# Solve 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

a_cnt, b_cnt = map(int, input().split())
a = set(input().split())
b = set(input().split())

print(len(a ^ b))

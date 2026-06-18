# Solve 2026-06-14

import sys

input = lambda: sys.stdin.readline().rstrip()

a = int(input())
b = int(input())

print(a * (b % 10))
print(a * (b // 10 % 10))
print(a * (b // 100))
print(a * b)


# Solve 2023-10-11

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

print("?", 1)
sys.stdout.flush()
s = int(input())

print("?", n)
sys.stdout.flush()
e = int(input())

print("!", e - s)
sys.stdout.flush()

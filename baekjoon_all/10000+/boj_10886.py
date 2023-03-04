# Solve 2023-03-04

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = [int(input()) for _ in range(n)]

if li.count(0) > li.count(1):
    print("Junhee is not cute!")
else:
    print("Junhee is cute!")

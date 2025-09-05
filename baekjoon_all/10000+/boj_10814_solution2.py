# Solve 2022-05-30
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
members = []

for i in range(n):
    mem = input().split()
    mem = [int(mem[0]), mem[1], i]
    members.append(mem)

members.sort(key=lambda x: (x[0], x[2]))

for mem in members:
    print(mem[0], mem[1])

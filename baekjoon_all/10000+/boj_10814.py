# Solve 2022-05-30
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
members = [[] for _ in range(201)]

for _ in range(n):
    age, name = input().split()
    age = int(age)
    members[age].append(name)

for age in range(len(members)):
    for name in members[age]:
        print(age, name)

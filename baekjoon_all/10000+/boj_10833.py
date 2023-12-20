# Solve 2023-12-20

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = [input().split() for _ in range(n)]

print(sum(map(lambda x: int(x[1]) % int(x[0]), li)))

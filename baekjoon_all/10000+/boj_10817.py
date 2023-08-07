# Solve 2022-05-28
# Update 2023-08-07

import sys

input = lambda : sys.stdin.readline().rstrip()

li = list(map(int, input().split()))
print(sorted(li)[1])

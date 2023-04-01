# Solve 2023-03-31

import sys

input = lambda : sys.stdin.readline().rstrip()

li = list(filter(lambda x: int(x) > 0, input().split()))
print(len(li))

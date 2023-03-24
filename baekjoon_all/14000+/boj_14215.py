# Solve 2023-03-23

import sys

input = lambda : sys.stdin.readline().rstrip()

lengths = list(sorted(map(int, input().split())))
if lengths[2] >= lengths[0] + lengths[1]:
    lengths[2] = lengths[0] + lengths[1] - 1
print(sum(lengths))

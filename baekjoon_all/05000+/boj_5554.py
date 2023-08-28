# Solve 2022-05-31
# Update 2023-08-28

import sys

input = lambda : sys.stdin.readline().rstrip()

ans = sum([int(input()) for _ in range(4)])

print(ans // 60, ans % 60, sep="\n")

# Solve 2023-10-09

import sys
from bisect import bisect_left, bisect_right

input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())
string_list = sorted([input() for _ in range(n)])
ans = 0

for _ in range(m):
    query = input()

    if bisect_right(string_list, query) - bisect_left(string_list, query) > 0:
        ans += 1

print(ans)

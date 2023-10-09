# Solve 2023-10-09

import sys
from bisect import bisect_left, bisect_right

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

num_list = sorted(map(int, input().split()))

m = int(input())

query_list = map(int, input().split())
ans_list = map(lambda x: bisect_right(num_list, x) - bisect_left(num_list, x), query_list)

print(*ans_list)

# Solve 2023-10-09

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

num_list = map(int, input().split())
num_cnt = Counter(num_list)

m = int(input())

query_list = map(int, input().split())
ans_list = map(lambda x: num_cnt[x], query_list)

print(*ans_list)

# Solve 2023-10-09

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())

num_list = list(map(int, input().split()))
num_dict = {}

for num in num_list:
    num_dict[num] = 1

m = int(input())

query_list = map(int, input().split())
ans_list = map(lambda x: 1 if x in num_dict else 0, query_list)

print(*ans_list)

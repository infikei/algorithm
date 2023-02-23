# Solve 2022-06-01
# Update 2023-02-23

import sys

input = lambda : sys.stdin.readline().rstrip()

n = int(input())
li = list(map(int, input().split()))
li2 = sorted(set(li))
dic = {li2[i]: i for i in range(len(li2))}

for a in li:
    print(dic[a], end=" ")

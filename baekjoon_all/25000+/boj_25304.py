# Solve 2023-02-22
# Update 2023-10-10

import sys

input = lambda : sys.stdin.readline().rstrip()

amount = int(input())
n = int(input())
calculated_amount = 0

for i in range(n):
    item_price, item_cnt = map(int, input().split())
    calculated_amount += item_price * item_cnt

if amount == calculated_amount:
    print("Yes")
else:
    print("No")

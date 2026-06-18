# Solve 2026-06-14

import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
nums = list(map(int, input().split()))
m = int(input())

divisor_sum = 0
multiple_sum = 0

for num in nums:
    if m % num == 0:
        divisor_sum += num

    if num % m == 0:
        multiple_sum += num

print(divisor_sum)
print(multiple_sum)

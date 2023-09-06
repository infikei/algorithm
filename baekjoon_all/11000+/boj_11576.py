# Solve 2023-03-02
# Update 2023-09-06

import sys

input = lambda : sys.stdin.readline().rstrip()

a, b = map(int, input().split())
m = int(input())

li = list(map(int, input().split()))
num = 0

for x in li:
    num *= a
    num += x

li = []

while num > 0:
    li.append(num % b)
    num //= b

print(*reversed(li), sep=" ")

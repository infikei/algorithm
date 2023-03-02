# Solve 2023-03-02

import sys

input = lambda : sys.stdin.readline().rstrip()

a, b = map(int, input().split())
m = int(input())

li = list(map(int, input().split()))
num = 0
for i in li:
    num *= a
    num += i

li = []
while num > 0:
    li.append(num % b)
    num //= b

print(*reversed(li), sep=" ")

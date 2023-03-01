# Solve 2022-05-24
# Update 2023-03-01

import sys

input = lambda : sys.stdin.readline().rstrip()

def is_prime(k):
    if k < 2:
        return False
    for i in range(2, int(k ** 0.5) + 1):
        if k % i == 0:
            return False
    return True

n = int(input())
li = list(map(int, input().split()))

ans = 0
for i in li:
    if is_prime(i):
        ans += 1

print(ans)

# Solve 2022-05-21
# Update 2025-09-04

import sys

input = lambda: sys.stdin.readline().rstrip()

def solution(n):
    for sugar5 in range(n // 5, -1, -1):
        if (n - sugar5 * 5) % 3 == 0:
            sugar3 = (n - sugar5 * 5) // 3
            return sugar3 + sugar5

    return -1


n = int(input())
print(solution(n))

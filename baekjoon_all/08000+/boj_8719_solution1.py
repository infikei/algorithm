# Solve 2023-12-10

# Python 3 제출 : 시간 초과
# PyPy3 제출 : 통과

import sys

input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    x, w = map(int, input().split())
    ans = 0

    while x < w:
        x *= 2
        ans += 1

    print(ans)

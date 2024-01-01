# Solve 2023-12-30

import sys

input = lambda : sys.stdin.readline().rstrip()

winning = [list(map(int, input().split())) for _ in range(6)]

while True:
    if (number := int(input())) == -1:
        break

    ans = 0

    if winning[0][0] == number:
        ans += winning[0][1]

    if winning[1][0] == number // 1000:
        ans += winning[1][1]

    if winning[2][0] == number // 1000:
        ans += winning[2][1]

    if winning[3][0] == number % 1000:
        ans += winning[3][1]

    if winning[4][0] == number % 1000:
        ans += winning[4][1]

    if winning[5][0] == number % 100:
        ans += winning[5][1]

    print(ans)

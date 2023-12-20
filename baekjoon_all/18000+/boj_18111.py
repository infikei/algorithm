# Solve 2022-05-22
# Update 2023-12-20

import sys
from collections import Counter

input = lambda : sys.stdin.readline().rstrip()

n, m, b = map(int, input().split())
board = []

for _ in range(n):
    board += list(map(int, input().split()))

board = Counter(board)
time_min = 500 * 500 * 256 * 2
height_ans = 0

for height in range(min(board), max(board) + 1):
    # 블록을 놓아야 하는 횟수
    higher_cnt = sum([board[h] * (height - h) for h in range(min(board), height)])

    # 블록을 제거해야 하는 횟수
    lower_cnt = sum([board[h] * (h - height) for h in range(height + 1, max(board) + 1)])

    # 기존에 가지고 있는 블록의 개수와 제거해야 하는 블록의 개수의 총합이
    # 놓아야 하는 블록의 개수 이상이어야 한다.
    if b + lower_cnt >= higher_cnt:
        time = lower_cnt * 2 + higher_cnt

        if time <= time_min:
            time_min = time
            height_ans = height

print(time_min, height_ans)


import sys
input = sys.stdin.readline

N, M, B = map(int, input().split())
board = [0] * N
for i in range(N):
    board[i] = list(map(int, input().split()))
time_ans = 1000000000000000000

board_min = min(map(min, board))
board_max = max(map(max, board))

for height in range(board_min, board_max+1):
    lower = 0
    higher = 0
    for i in range(N):
        for j in range(M):
            a = board[i][j] - height
            if a > 0:
                lower += a
            else:
                higher -= a
    if B + lower >= higher:
        time = lower * 2 + higher
        if time <= time_ans:
            time_ans = time
            height_ans = height

print(time_ans, height_ans)

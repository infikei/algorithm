# Solve 2022-05-26
# Update 2023-10-14

n, m = map(int, input().split())

board = [input() for _ in range(n)]

ans = 32

for i in range(0, n - 7):
    for j in range(0, m - 7):
        change_cnt = 0

        for row in range(i, i + 8):
            for col in range(j, j + 8):
                if (row + col) % 2 == 0:
                    if board[row][col] == "B":
                        change_cnt += 1
                else:
                    if board[row][col] == "W":
                        change_cnt += 1

        change_cnt = min(change_cnt, 64 - change_cnt)

        ans = min(ans, change_cnt)

print(ans)

n, m = map(int, input().split())
board = [0] * n
for i in range(n):
    board[i] = list(input())

ans = 1000
i, j = 0, 0
while True:
    ii, jj = i, j
    change = 0
    while True:
        if (ii+jj) % 2 == 0:
            if board[ii][jj] == "B":
                change += 1
        else:
            if board[ii][jj] == "W":
                change += 1
        jj += 1
        if jj == j + 8:
            ii += 1
            if ii == i + 8:
                break
            jj = j

    if change > 32:
        change = 64 - change
    if change < ans:
        ans = change
        if ans == 0:
            break
    j += 1
    if j == m - 7:
        i += 1
        if i == n - 7:
            break
        j = 0

print(ans)

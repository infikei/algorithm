# Solve 2022-06-01
# Update 2023-12-14

# Python 3 제출 : 시간 초과
# PyPy3 제출 : 통과

def n_queens(n, row = 0):
    if row == n:
        return 1

    res = 0

    for col in range(n):
        board[row] = col

        for i in range(row):
            if board[i] == board[row] or abs(board[i] - board[row]) == row - i:
                break
        else:
            res += n_queens(n, row + 1)

    return res


n = int(input())

board = [0] * n

print(n_queens(n))

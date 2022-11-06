# PyPy3로 성공한 코드, 공부할 때는 추후 작성한 C++ 코드로 보는 것을 추천함

import sys


def dfs(n, row=0):
    if row == n:
        return 1
    ans = 0
    for col in range(n):
        queen[row] = col
        for i in range(row):
            if queen[i] == queen[row]:
                break
            if abs(queen[i] - queen[row]) == (row-i):
                break
        else:
            ans += dfs(n, row+1)
    return ans


n = int(sys.stdin.readline())
queen = [0] * n
print(dfs(n))

import sys


def w(a, b, c):
    if min(a, b, c) <= 0:
        return 1
    if max(a, b, c) > 20:
        return w(20, 20, 20)

    if dp[a][b][c] != -1:
        return dp[a][b][c]

    if a < b and b < c:
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    else:
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + \
            w(a-1, b, c-1) - w(a-1, b-1, c-1)
    return dp[a][b][c]


dp = [[[-1 for _ in range(21)] for _ in range(21)] for _ in range(21)]

while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == -1 and b == -1 and c == -1:
        break
    print("w({}, {}, {}) = {}".format(a, b, c, w(a, b, c)))

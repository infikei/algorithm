# Solve 2022-06-02
# Update 2023-12-11

import sys

input = lambda : sys.stdin.readline().rstrip()

dp = [[[1 for _ in range(21)] for _ in range(21)] for _ in range(21)]

for a in range(1, 21):
    for b in range(1, 21):
        for c in range(1, 21):
            if a < b and b < c:
                dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c]
            else:
                dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c]\
                        + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1]

while True:
    a, b, c = map(int, input().split())

    if a == -1 and b == -1 and c == -1:
        break

    ans = 1

    if min(a, b, c) <= 0:
        ans = 1
    elif max(a, b, c) > 20:
        ans = dp[20][20][20]
    else:
        ans = dp[a][b][c]

    print("w({}, {}, {}) = {}".format(a, b, c, ans))

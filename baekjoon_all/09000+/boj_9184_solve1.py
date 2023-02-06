import sys

dp = [[[1 for _ in range(21)] for _ in range(21)] for _ in range(21)]

a = 1
for b in range(1, 21):
    for c in range(1, 21):
        if a < b and b < c:
            dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c]
        else:
            dp[a][b][c] = 2

for a in range(2, 21):
    for b in range(1, 21):
        for c in range(1, 21):
            if a < b and b < c:
                dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c]
            else:
                dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + \
                    dp[a-1][b][c-1] - dp[a-1][b-1][c-1]

while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == -1 and b == -1 and c == -1:
        break
    if min(a, b, c) <= 0:
        print("w({}, {}, {}) = {}".format(a, b, c, 1))
    elif max(a, b, c) > 20:
        print("w({}, {}, {}) = {}".format(a, b, c, dp[20][20][20]))
    else:
        print("w({}, {}, {}) = {}".format(a, b, c, dp[a][b][c]))

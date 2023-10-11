// Solve 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    // input

    int n;
    cin >> n;

    vector<vector<int> > board(n + 1, vector<int>(n + 1, 0));

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            cin >> board[row][col];
        }
    }

    int y_r, y_c;
    cin >> y_r >> y_c;

    // answer 1

    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

    for (int row = 1; row <= y_r; row++) {
        for (int col = 1; col <= y_c; col++) {
            dp[row][col] = board[row][col] + max(dp[row - 1][col], dp[row][col - 1]);
        }
    }

    for (int row = y_r; row <= n; row++) {
        for (int col = y_c; col <= n; col++) {
            dp[row][col] = board[row][col] + max(dp[row - 1][col], dp[row][col - 1]);
        }
    }

    int ans_1 = dp[n][n];

    // answer 2

    board[y_r][y_c] = 0;

    if (y_r == 1) {
        for (int col = y_c + 1; col <= n; col++) {
            board[y_r][col] = 0;
        }
    }
    else if (y_r == n) {
        for (int col = y_c - 1; col >= 1; col--) {
            board[y_r][col] = 0;
        }
    }

    if (y_c == 1) {
        for (int row = y_r + 1; row <= n; row++) {
            board[row][y_c] = 0;
        }
    }
    else if (y_c == n) {
        for (int row = y_r - 1; row >= 1; row--) {
            board[row][y_c] = 0;
        }
    }

    dp.assign(n + 1, vector<int>(n + 1, 0));

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            dp[row][col] = board[row][col] + max(dp[row - 1][col], dp[row][col - 1]);
        }
    }

    int ans_2 = dp[n][n];

    // print

    cout << ans_1 << ' ' << ans_2 << '\n';

    return 0;
}

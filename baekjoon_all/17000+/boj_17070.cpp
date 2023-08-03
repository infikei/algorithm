// Solve 2023-08-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int board[16][16];
int dp[32][32][3];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j <= 1) continue;
            if (board[i][j] == 1) continue;

            if (j >= 1) dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
            if (i >= 1) dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];

            if (i >= 1 && j >= 1 && board[i][j - 1] == 0 && board[i - 1][j] == 0) {
                dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << '\n';

    return 0;
}

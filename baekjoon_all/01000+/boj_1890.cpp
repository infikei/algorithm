// Solve 2022-09-14
// Update 2023-07-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int board[100][100];
ll dp[100][100];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> board[row][col];
        }
    }

    dp[n - 1][n - 1] = 1;

    for (int row = n - 1; row >= 0; row--) {
        for (int col = n - 1; col >= 0; col--) {
            if (board[row][col] == 0) continue;

            int x = board[row][col];

            if (row + x < n) {
                dp[row][col] += dp[row + x][col];
            }

            if (col + x < n) {
                dp[row][col] += dp[row][col + x];
            }
        }
    }

    cout << dp[0][0] << '\n';

    return 0;
}

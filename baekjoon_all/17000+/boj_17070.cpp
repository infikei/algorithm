// Solve 2023-08-02
// Update 2024-02-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int board[16][16];
int memo[16][16][3];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    memo[0][1][0] = 1;

    for (int y = 2; y < n; y++) {
        if (board[0][y] == 0) {
            memo[0][y][0] = memo[0][y - 1][0] + memo[0][y - 1][1];
        }
    }

    for (int x = 1; x < n; x++) {
        for (int y = 1; y < n; y++) {
            if (board[x][y] == 0) {
                memo[x][y][0] = memo[x][y - 1][0] + memo[x][y - 1][1];
                memo[x][y][2] = memo[x - 1][y][1] + memo[x - 1][y][2];

                if (board[x][y - 1] == 0 && board[x - 1][y] == 0) {
                    memo[x][y][1] = memo[x - 1][y - 1][0] + memo[x - 1][y - 1][1] + memo[x - 1][y - 1][2];
                }
            }
        }
    }

    cout << memo[n - 1][n - 1][0] + memo[n - 1][n - 1][1] + memo[n - 1][n - 1][2] << '\n';

    return 0;
}

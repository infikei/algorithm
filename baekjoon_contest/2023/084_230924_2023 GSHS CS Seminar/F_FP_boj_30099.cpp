// Solve 2023-09-26
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int drow[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dcol[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));
    vector<vector<int>> board_cnt(n, vector<int>(n, 0));

    for (int col = 0; col < n; col++) {
        cin >> board[0][col];
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> board_cnt[row][col];
        }
    }

    for (int row = 1; row < n; row++) {
        int prow = row - 1;

        for (int col = 0; col < n; col++) {
            for (int d = 0; d < 5; d++) {
                int nrow = prow + drow[d];
                int ncol = col + dcol[d];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) continue;

                if (board[nrow][ncol] == 0) board_cnt[prow][col]--;
            }
        }

        for (int col = 2; col < n; col += 3) {
            if (board_cnt[prow][col - 2] < board_cnt[prow][col - 1]) {
                board[row][col] = 0;

                board_cnt[prow][col - 1]--;
                board_cnt[prow][col]--;
                if (col + 1 < n) board_cnt[prow][col + 1]--;
            }
            else {
                board[row][col] = 1;
            }
        }

        for (int col = n - 3; col >= 0; col -= 3) {
            if (board_cnt[prow][col + 1] > board_cnt[prow][col + 2]) {
                board[row][col] = 0;

                if (col - 1 >= 0) board_cnt[prow][col - 1]--;
                board_cnt[prow][col]--;
                board_cnt[prow][col + 1]--;
            }
            else {
                board[row][col] = 1;
            }
        }

        for (int col = (n % 3 == 0 ? 1 : 0); col < n; col += 3) {
            if (board_cnt[prow][col] == 1) board[row][col] = 0;
            else board[row][col] = 1;
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << board[row][col] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

// Solve 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> board(n, "");

    for (string &row : board) {
        cin >> row;
    }

    int ans = 32;

    for (int i = 0, ie = n - 7; i < ie; i++) {
        for (int j = 0, je = m - 7; j < je; j++) {
            int change_cnt = 0;

            for (int row = i, row_end = i + 8; row < row_end; row++) {
                for (int col = j, col_end = j + 8; col < col_end; col++) {
                    if ((row + col) % 2 == 0) {
                        if (board[row][col] == 'B') {
                            change_cnt++;
                        }
                    }
                    else {
                        if (board[row][col] == 'W') {
                            change_cnt++;
                        }
                    }
                }
            }

            change_cnt = min(change_cnt, 64 - change_cnt);

            ans = min(ans, change_cnt);
        }
    }

    cout << ans << '\n';

    return 0;
}

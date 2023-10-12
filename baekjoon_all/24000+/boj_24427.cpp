// Solve 2023-10-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int> > board(n + 1, vector<int>(n + 1, 0));

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            cin >> board[row][col];
        }
    }

    int p;
    cin >> p;

    vector<vector<bool> > board_check(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < p; i++) {
        int row, col;
        cin >> row >> col;

        board_check[row][col] = true;
    }

    vector<vector<int> > dp_not_pass(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > dp_pass(n + 1, vector<int>(n + 1, 0));

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if (row == 1 && col == 1) {
                dp_not_pass[row][col] = board[row][col];
                continue;
            }

            dp_not_pass[row][col] = max(dp_not_pass[row - 1][col], dp_not_pass[row][col - 1]);

            if (dp_not_pass[row][col] != 0) {
                dp_not_pass[row][col] += board[row][col];
            }

            dp_pass[row][col] = max(dp_pass[row - 1][col], dp_pass[row][col - 1]);

            if (dp_pass[row][col] != 0) {
                dp_pass[row][col] += board[row][col];
            }

            if (board_check[row][col]) {
                dp_pass[row][col] = max(dp_pass[row][col], dp_not_pass[row][col]);
                dp_not_pass[row][col] = 0;
            }
        }
    }

    cout << dp_pass[n][n] << '\n';

    return 0;
}

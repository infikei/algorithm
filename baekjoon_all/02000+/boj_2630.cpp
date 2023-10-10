// Solve 2022-12-06
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

void solve(int r0, int c0, int size, const vector<vector<int> > &board, vector<int> &ans) {
    bool same_color = true;

    for (int r = r0, r_end = r0 + size; r < r_end; r++) {
        for (int c = c0, c_end = c0 + size; c < c_end; c++) {
            if (board[r][c] != board[r0][c0]) {
                same_color = false;
                break;
            }
        }

        if (!same_color) break;
    }

    if (same_color) {
        ans[board[r0][c0]]++;
    }
    else {
        int next_size = size / 2;

        solve(r0, c0, next_size, board, ans);
        solve(r0, c0 + next_size, next_size, board, ans);
        solve(r0 + next_size, c0, next_size, board, ans);
        solve(r0 + next_size, c0 + next_size, next_size, board, ans);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int> > board(n, vector<int>(n));

    for (vector<int> &row : board) {
        for (int &col : row) {
            cin >> col;
        }
    }

    vector<int> ans(2, 0);

    solve(0, 0, n, board, ans);

    cout << ans[0] << '\n';
    cout << ans[1] << '\n';

    return 0;
}

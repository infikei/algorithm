// Solve 2022-07-26
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool check_board(vector<int> &board, int row) {
    for (int i = 1; i < row; i++) {
        if (board[row] == board[i] || abs(board[row] - board[i]) == row - i) {
            return false;
        }
    }

    return true;
}

void n_queens(int n, vector<int> &board, int &ans, int row = 1) {
    if (row == n + 1) {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        board[row] = i;

        if (!check_board(board, row)) continue;

        n_queens(n, board, ans, row + 1);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> board(15, 0);
    int ans = 0;

    n_queens(n, board, ans);

    cout << ans << '\n';

    return 0;
}

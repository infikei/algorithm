// Solve 2022-07-26
// Update 2023-10-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int board[15];
int n, ans;

bool check(int row) {
    for (int i = 1; i < row; i++) {
        if (board[row] == board[i] || abs(board[row] - board[i]) == row - i) {
            return false;
        }
    }

    return true;
}

void n_queens(int row = 1) {
    if (row == n + 1) {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        board[row] = i;

        if (!check(row)) continue;

        n_queens(row + 1);
    }
}

int main() {
    FASTIO;

    cin >> n;

    n_queens();

    cout << ans << '\n';

    return 0;
}

// Solve 2022-07-26
// Update 2025-03-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool check_board(vector<int> &board, int row) {
    for (int i = 1; i < row; i++) {
        if (board[row] == board[i] || abs(board[row] - board[i]) == row - i) {
            return false;
        }
    }

    return true;
}

int n_queens(int n, vector<int> &board, int row) {
    if (row == n + 1) {
        return 1;
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        board[row] = i;

        if (check_board(board, row)) {
            res += n_queens(n, board, row + 1);
        }
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> board(15, 0);
    int ans = n_queens(n, board, 1);

    cout << ans << '\n';

    return 0;
}

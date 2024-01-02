// Solve 2024-01-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;

    vector<vector<int>> board(n, vector<int>(n, 0));

    for (vector<int> &row : board) {
        for (int &col : row) {
            cin >> col;
        }
    }

    bool ans = true;

    for (int r = 0; r < n; r++) {
        if (board[r][b] > board[a][b]) {
            ans = false;
            break;
        }
    }

    if (ans) {
        for (int c = 0; c < n; c++) {
            if (board[a][c] > board[a][b]) {
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "HAPPY" : "ANGRY") << '\n';

    return 0;
}

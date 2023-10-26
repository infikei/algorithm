// Solve 2023-10-25

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

    // 1.

    for (int row = 0; row < n; row++) {
        bool flag = false;
        int cur = 0;

        for (int col = 0; col < m; col++) {
            if (board[row][col] == '#') {
                cur++;
                flag = true;
            }
            else {
                if (cur > 0) {
                    cout << cur << ' ';
                    cur = 0;
                }
            }
        }

        if (cur > 0) {
            cout << cur << ' ';
        }

        if (!flag) {
            cout << 0 << ' ';
        }

        cout << '\n';
    }

    // 2.

    for (int col = 0; col < m; col++) {
        bool flag = false;
        int cur = 0;

        for (int row = 0; row < n; row++) {
            if (board[row][col] == '#') {
                cur++;
                flag = true;
            }
            else {
                if (cur > 0) {
                    cout << cur << ' ';
                    cur = 0;
                }
            }
        }

        if (cur > 0) {
            cout << cur << ' ';
        }

        if (!flag) {
            cout << 0 << ' ';
        }

        cout << '\n';
    }

    return 0;
}

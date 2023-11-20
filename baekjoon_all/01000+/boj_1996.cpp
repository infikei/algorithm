// Solve 2023-11-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    int n;
    cin >> n;

    vector<string> board;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;

        board.push_back(row);
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == '.') {
                int cur = 0;

                for (int d = 0; d < 8; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (board[nr][nc] == '.') continue;

                    cur += board[nr][nc] - '0';
                }

                if (cur < 10) cout << (char)('0' + cur);
                else cout << 'M';
            }
            else {
                cout << '*';
            }
        }

        cout << '\n';
    }

    return 0;
}

// Solve 2025-02-06
// Update 2025-02-24

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

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    FASTIO;

    while (true) {
        int r, c;
        cin >> r >> c;

        if (r == 0 && c == 0) break;

        vector<string> board(r, "");

        for (string &row : board) {
            cin >> row;
        }

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (board[x][y] == '*') continue;

                int cnt = 0;

                for (int d = 0; d < 8; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '*') {
                        cnt++;
                    }
                }

                board[x][y] = '0' + cnt;
            }
        }

        for (string &row : board) {
            cout << row << '\n';
        }
    }

    return 0;
}

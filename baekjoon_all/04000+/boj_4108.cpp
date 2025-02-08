// Solve 2025-02-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

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
            println(row);
        }
    }

    return 0;
}

// Solve 2024-12-26

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

    int n;
    cin >> n;

    vector<string> board_bomb(n);

    for (string &row : board_bomb) {
        cin >> row;
    }

    vector<string> board_open(n);

    for (string &row : board_open) {
        cin >> row;
    }

    vector<string> board(n, string(n, '.'));
    bool bomb_open = false;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board_open[x][y] != 'x') continue;

            if (board_bomb[x][y] == '*') {
                board[x][y] = '*';
                bomb_open = true;
                continue;
            }

            int cnt = 0;

            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if (board_bomb[nx][ny] == '*') {
                    cnt++;
                }
            }

            board[x][y] = '0' + cnt;
        }
    }

    if (bomb_open) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (board_bomb[x][y] == '*') {
                    board[x][y] = '*';
                }
            }
        }
    }

    for (string &row : board) {
        println(row);
    }

    return 0;
}

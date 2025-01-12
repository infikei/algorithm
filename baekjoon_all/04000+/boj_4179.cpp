// Solve 2025-01-09

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    vector<string> board(r);

    for (string &row : board) {
        cin >> row;
    }

    queue<pii> que_jihoon;
    queue<pii> que_fire;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (board[x][y] == 'J') {
                que_jihoon.emplace(x, y);
            }
            else if (board[x][y] == 'F') {
                que_fire.emplace(x, y);
            }
        }
    }

    bool escaped = false;
    int moved_cnt = 0;

    while (!que_jihoon.empty()) {
        moved_cnt++;
        int iter = size(que_fire);

        while (iter-- > 0) {
            pii cur = que_fire.front();
            que_fire.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (board[nx][ny] == '#' || board[nx][ny] == 'F') continue;

                board[nx][ny] = 'F';
                que_fire.emplace(nx, ny);
            }
        }

        iter = size(que_jihoon);

        while (iter-- > 0) {
            pii cur = que_jihoon.front();
            que_jihoon.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    escaped = true;
                    continue;
                }

                if (board[nx][ny] != '.') continue;

                board[nx][ny] = 'J';
                que_jihoon.emplace(nx, ny);
            }
        }

        if (escaped) break;
    }

    if (escaped) {
        println(moved_cnt);
    }
    else {
        println("IMPOSSIBLE");
    }

    return 0;
}

// Solve 2024-12-30

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

int dx[4] = { 0, 1, 1, 1 };
int dy[4] = { 1, 1, 0, -1 };

int main() {
    FASTIO;

    vector<string> board(8);

    for (string &row : board) {
        cin >> row;
    }

    int cnt = 0;
    bool valid = true;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (board[x][y] != '*') continue;

            cnt++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                while (nx < 8 && ny >= 0 && ny < 8) {
                    if (board[nx][ny] == '*') {
                        valid = false;
                        break;
                    }

                    nx += dx[d];
                    ny += dy[d];
                }

                if (!valid) break;
            }

            if (!valid) break;
        }

        if (!valid) break;
    }

    println((valid && cnt == 8) ? "valid" : "invalid");

    return 0;
}

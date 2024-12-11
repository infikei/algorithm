// Solve 2024-12-11

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

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    vector<string> board(r * 2, string(c * 2, '.'));

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cin >> board[x][y];

            board[x][c * 2 - 1 - y] = board[x][y];
            board[r * 2 - 1 - x][y] = board[x][y];
            board[r * 2 - 1 - x][c * 2 - 1 - y] = board[x][y];
        }
    }

    int a, b;
    cin >> a >> b;

    board[a - 1][b - 1] = (board[a - 1][b - 1] == '.' ? '#' : '.');

    for (string &row : board) {
        println(row);
    }

    return 0;
}

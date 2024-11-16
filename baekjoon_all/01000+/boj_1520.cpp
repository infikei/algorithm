// Solve 2023-01-04
// Update 2024-11-03

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

int m, n;
int board[500][500];
int memo[500][500];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        return 1;
    }

    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    memo[x][y] = 0;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }

        if (board[x][y] > board[nx][ny]) {
            memo[x][y] += dfs(nx, ny);
        }
    }

    return memo[x][y];
}

int main() {
    FASTIO;

    cin >> m >> n;

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
            memo[x][y] = -1;
        }
    }

    println(dfs(0, 0));

    return 0;
}

// Solve 2025-05-07

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int r, c, k;
string board[5];
bool visited[5][5];
int ans = 0;

void dfs(int depth, int x, int y) {
    if (depth == k) {
        if (x == 0 && y == c - 1) {
            ans++;
        }

        return;
    }

    visited[x][y] = true;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (visited[nx][ny] || board[nx][ny] == 'T') continue;

        dfs(depth + 1, nx, ny);
    }

    visited[x][y] = false;
}

int main() {
    FASTIO;

    cin >> r >> c >> k;

    for (int x = 0; x < r; x++) {
        cin >> board[x];
    }

    dfs(1, r - 1, 0);

    cout << ans << '\n';

    return 0;
}

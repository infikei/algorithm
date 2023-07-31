// Solve 2023-07-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, board[500][500], dp[500][500];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
    if (dp[x][y] > 0) return dp[x][y];

    int res = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[x][y] >= board[nx][ny]) continue;

        res = max(res, dfs(nx, ny));
    }

    return dp[x][y] = ++res;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans << '\n';

    return 0;
}

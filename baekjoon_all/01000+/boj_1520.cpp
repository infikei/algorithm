// Solve 2023-01-04
// Update 2023-07-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int m, n;
int graph[500][500], dp[500][500];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
    if (x == m - 1 && y == n - 1) return 1;

    if (dp[x][y] == -1) {
        dp[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (graph[x][y] <= graph[nx][ny]) continue;
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    FASTIO;

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}

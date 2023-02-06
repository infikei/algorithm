#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 500;
int m, n, ans, map[MAX_N][MAX_N], dp[MAX_N][MAX_N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs(int x = 0, int y = 0) {
    if (x == m - 1 && y == n - 1) return 1;

    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (map[nx][ny] < map[x][y]) {
                    dp[x][y] += dfs(nx, ny);
                }
            }
        }
    }

    return dp[x][y];
}

int main() {
    fastio;

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    ans = dfs();
    cout << ans << '\n';

    return 0;
}
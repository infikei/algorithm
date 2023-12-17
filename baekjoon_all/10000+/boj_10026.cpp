// Solve 2023-04-11
// Update 2023-12-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int r, c;
    Point(int r, int c) : r(r), c(c) {}
};

int main() {
    FASTIO;

    int dr[4] = { 0, 0, 1, -1 };
    int dc[4] = { 1, -1, 0, 0 };

    int n;
    cin >> n;

    vector<string> board(n);

    for (string &row : board) {
        cin >> row;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<Point> bfs_que;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            visited[i][j] = true;
            bfs_que.emplace(i, j);
            ans++;
            char color = board[i][j];

            while (!bfs_que.empty()) {
                Point now = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = now.r + dr[d];
                    int nc = now.c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc] || board[nr][nc] != color) continue;

                    visited[nr][nc] = true;
                    bfs_que.emplace(nr, nc);
                }
            }
        }
    }

    visited.assign(n, vector<bool>(n, false));
    int ans2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            visited[i][j] = true;
            bfs_que.emplace(i, j);
            ans2++;
            char color = board[i][j];

            if (color == 'G') color = 'R';

            while (!bfs_que.empty()) {
                Point now = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = now.r + dr[d];
                    int nc = now.c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                    char color2 = board[nr][nc];

                    if (color2 == 'G') color2 = 'R';

                    if (visited[nr][nc] || color2 != color) continue;

                    visited[nr][nc] = true;
                    bfs_que.emplace(nr, nc);
                }
            }
        }
    }

    cout << ans << ' ' << ans2 << '\n';

    return 0;
}

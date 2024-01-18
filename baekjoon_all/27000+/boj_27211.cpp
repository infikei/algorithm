// Solve 2024-01-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    FASTIO;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));

    for (vector<int> &row : board) {
        for (int &x : row) {
            cin >> x;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] || board[i][j] != 0) continue;

            visited[i][j] = true;
            ans++;
            queue<Point> bfs_que;
            bfs_que.emplace(i, j);

            while (!bfs_que.empty()) {
                Point cur = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx < 0) nx += n;
                    else if (nx >= n) nx -= n;

                    if (ny < 0) ny += m;
                    else if (ny >= m) ny -= m;

                    if (visited[nx][ny] || board[nx][ny] != 0) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

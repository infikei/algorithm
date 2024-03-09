// Solve 2024-03-08

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

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int board[50][50];
bool visited[50][50];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
        }
    }

    int max_depth = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 1) continue;

            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < m; y2++) {
                    visited[x2][y2] = false;
                }
            }

            visited[x][y] = true;
            queue<Point> bfs_que;
            bfs_que.emplace(x, y);
            int cur_depth = 0;
            bool found = false;

            while (!bfs_que.empty()) {
                ++cur_depth;
                int cur_iter = SIZE(bfs_que);

                while (cur_iter-- > 0) {
                    Point cur = bfs_que.front();
                    bfs_que.pop();

                    for (int d = 0; d < 8; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

                        if (board[nx][ny] == 1) {
                            found = true;
                            break;
                        }
                        else {
                            visited[nx][ny] = true;
                            bfs_que.emplace(nx, ny);
                        }
                    }
                }

                if (found) break;
            }

            max_depth = max(max_depth, cur_depth);
        }
    }

    cout << max_depth << '\n';

    return 0;
}

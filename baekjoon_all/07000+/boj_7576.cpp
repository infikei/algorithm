// Solve 2022-12-07
// Update 2024-02-16

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
    cin >> m >> n;

    int board[1000][1000];
    queue<Point> bfs_que;
    int not_ripe = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];

            if (board[x][y] == 0) {
                not_ripe++;
            }
            else if (board[x][y] == 1) {
                bfs_que.emplace(x, y);
            }
        }
    }

    int cur_day = 0;

    while (not_ripe > 0 && !bfs_que.empty()) {
        cur_day++;
        int cur_iter = SIZE(bfs_que);

        while (cur_iter-- > 0) {
            Point cur_pos = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur_pos.x + dx[d];
                int ny = cur_pos.y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0) {
                    board[nx][ny] = 1;
                    bfs_que.emplace(nx, ny);
                    not_ripe--;
                }
            }
        }
    }

    cout << (not_ripe > 0 ? -1 : cur_day) << '\n';

    return 0;
}

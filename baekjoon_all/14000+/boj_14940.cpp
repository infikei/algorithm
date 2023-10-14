// Solve 2023-10-14

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

    int board[1000][1000];
    Point ini(0, 0);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            int a;
            cin >> a;

            if (a == 1) {
                board[x][y] = -1;
            }
            else if (a == 2) {
                board[x][y] = 0;
                ini = { x, y };
            }
            else {
                board[x][y] = 0;
            }
        }
    }

    queue<Point> bfs_que;
    bfs_que.push(ini);

    int depth = 0;

    while (!bfs_que.empty()) {
        depth++;

        for (int i = 0, ie = SIZE(bfs_que); i < ie; i++) {
            Point now = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] >= 0) continue;

                board[nx][ny] = depth;
                bfs_que.emplace(nx, ny);
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cout << board[x][y] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

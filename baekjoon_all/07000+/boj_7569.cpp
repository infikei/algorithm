// Solve 2022-12-10
// Update 2023-10-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int z, x, y;
    Point(int z, int x, int y) : z(z), x(x), y(y) {}
};

int main() {
    FASTIO;

    int dz[6] = { 1, -1, 0, 0, 0, 0 };
    int dx[6] = { 0, 0, 1, -1, 0, 0 };
    int dy[6] = { 0, 0, 0, 0, 1, -1 };

    int n, m, h;
    cin >> m >> n >> h;

    int board[100][100][100];
    queue<Point> que;
    int ripe_cnt = 0, empty_cnt = 0;

    for (int hei = 0; hei < h; hei++) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                cin >> board[hei][row][col];

                if (board[hei][row][col] == 1) {
                    ripe_cnt++;
                    que.emplace(hei, row, col);
                }
                else if (board[hei][row][col] == -1) {
                    empty_cnt++;
                }
            }
        }
    }

    int ans = 0;

    while (true) {
        for (int i = 0, i_end = SIZE(que); i < i_end; i++) {
            Point now = que.front();
            que.pop();

            for (int d = 0; d < 6; d++) {
                int nz = now.z + dz[d];
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];

                if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if (board[nz][nx][ny] == 0) {
                    board[nz][nx][ny] = 1;
                    ripe_cnt++;
                    que.emplace(nz, nx, ny);
                }
            }
        }

        if (que.empty()) break;

        ans++;
    }

    if (h * n * m == ripe_cnt + empty_cnt) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}

// Solve 2022-12-07
// Update 2023-10-12

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

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    int n, m;
    cin >> m >> n;

    int board[1000][1000];
    queue<Point> que;
    int ripe_cnt = 0, empty_cnt = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> board[row][col];

            if (board[row][col] == 1) {
                ripe_cnt++;
                que.push({ row, col });
            }
            else if (board[row][col] == -1) {
                empty_cnt++;
            }
        }
    }

    int ans = 0;

    while (true) {
        for (int i = 0, i_end = SIZE(que); i < i_end; i++) {
            Point now = que.front();
            que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if (board[nx][ny] == 0) {
                    board[nx][ny] = 1;
                    ripe_cnt++;
                    que.push({ nx, ny });
                }
            }
        }

        if (que.empty()) break;

        ans++;
    }

    if (n * m == ripe_cnt + empty_cnt) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}

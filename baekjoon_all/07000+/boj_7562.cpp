// Solve 2022-10-08
// Update 2023-10-25

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

    int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int l, x0, y0, x1, y1;
        cin >> l >> x0 >> y0 >> x1 >> y1;

        if (x0 == x1 && y0 == y1) {
            cout << 0 << '\n';
            continue;
        }

        vector<vector<bool> > visited(l, vector<bool>(l, false));
        queue<Point> bfs_que;
        int depth = 0;

        visited[x0][y0] = true;
        bfs_que.emplace(x0, y0);

        while (true) {
            depth++;
            bool flag_find_ans = false;

            for (int i = 0, ie = SIZE(bfs_que); i < ie; i++) {
                Point cur = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 8; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx == x1 && ny == y1) {
                        flag_find_ans = true;
                        break;
                    }

                    if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                    if (visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                }

                if (flag_find_ans) break;
            }

            if (flag_find_ans) break;
        }

        cout << depth << '\n';
    }

    return 0;
}

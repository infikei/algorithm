// Solve 2022-09-28
// Update 2023-10-14

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

    int graph[50][50];

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int m, n, k;
        cin >> m >> n >> k;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                graph[row][col] = 0;
            }
        }

        for (int ki = 0; ki < k; ki++) {
            int x, y;
            cin >> x >> y;

            graph[x][y] = 1;
        }

        int cnt = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (graph[x][y] != 1) continue;

                graph[x][y] = 0;
                cnt++;

                queue<Point> que;
                que.emplace(x, y);

                while (!que.empty()) {
                    Point now = que.front();
                    que.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = now.x + dx[d];
                        int ny = now.y + dy[d];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (graph[nx][ny] != 1) continue;

                        graph[nx][ny] = 0;
                        que.emplace(nx, ny);
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}

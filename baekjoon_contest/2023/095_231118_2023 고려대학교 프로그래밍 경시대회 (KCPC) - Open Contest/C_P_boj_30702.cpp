// Solve 2023-11-18

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

    vector<string> a;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        a.push_back(s);
    }

    vector<string> b;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        b.push_back(s);
    }

    vector<vector<bool> > visited(n, vector<bool>(m, false));
    bool ans = true;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (visited[x][y]) continue;

            visited[x][y] = true;
            queue<Point> bfs_que;
            bfs_que.emplace(x, y);

            while (!bfs_que.empty()) {
                Point p = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = p.x + dx[d];
                    int ny = p.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (a[x][y] != a[nx][ny]) continue;
                    if (visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);

                    if (b[x][y] != b[nx][ny]) {
                        ans = false;
                        break;
                    }
                }
                if (!ans) break;
            }
            if (!ans) break;
        }
        if (!ans) break;
    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

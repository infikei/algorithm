// Solve 2022-08-10
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

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int board[50][50];
bool visited[50][50];

int main() {
    FASTIO;

    while (true) {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0) break;

        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                cin >> board[x][y];

                visited[x][y] = false;
            }
        }

        int area_cnt = 0;

        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                if (visited[x][y] || board[x][y] == 0) continue;

                area_cnt++;
                queue<Point> bfs_que;
                bfs_que.emplace(x, y);
                visited[x][y] = true;

                while (!bfs_que.empty()) {
                    Point cur = bfs_que.front();
                    bfs_que.pop();

                    for (int d = 0; d < 8; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];

                        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && board[nx][ny] == 1) {
                            bfs_que.emplace(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }

        cout << area_cnt << '\n';
    }

    return 0;
}

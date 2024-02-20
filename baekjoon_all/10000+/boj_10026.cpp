// Solve 2023-04-11
// Update 2024-02-20

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

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> board(n);

    for (string &row : board) {
        cin >> row;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<Point> bfs_que;
    int area_count = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (visited[x][y]) continue;

            area_count++;
            visited[x][y] = true;
            bfs_que.emplace(x, y);
            char color = board[x][y];

            while (!bfs_que.empty()) {
                Point cur = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || board[nx][ny] != color) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                }
            }
        }
    }

    visited.assign(n, vector<bool>(n, false));
    int area_count2 = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (visited[x][y]) continue;

            area_count2++;
            visited[x][y] = true;
            bfs_que.emplace(x, y);
            char color = (board[x][y] == 'G' ? 'R' : board[x][y]);

            while (!bfs_que.empty()) {
                Point cur = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || (board[nx][ny] == 'G' ? 'R' : board[nx][ny]) != color) continue;

                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                }
            }
        }
    }

    cout << area_count << ' ' << area_count2 << '\n';

    return 0;
}

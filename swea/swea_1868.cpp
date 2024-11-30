// Solve 2024-01-14

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int dx[8] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dy[8] = { -1, 1, -1, 0, 1, -1, 0, 1 };
int n;
string board[300];
bool visited[300][300];

bool check(int x, int y) {
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (board[nx][ny] == '*') {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == '.' && check(i, j)) {
                    ans++;
                    visited[i][j] = true;
                    queue<Point> bfs_que;
                    bfs_que.emplace(i, j);

                    while (!bfs_que.empty()) {
                        Point cur = bfs_que.front();
                        bfs_que.pop();

                        for (int d = 0; d < 8; d++) {
                            int nx = cur.x + dx[d];
                            int ny = cur.y + dy[d];

                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                                visited[nx][ny] = true;

                                if (check(nx, ny)) {
                                    bfs_que.emplace(nx, ny);
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == '.') {
                    ans++;
                }
            }
        }

        cout << '#' << ti << ' ' << ans << '\n';
    }

    return 0;
}

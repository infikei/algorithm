// Solve 2024-04-11

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

    int r, c;
    cin >> r >> c;

    vector<string> board(r, "");

    for (string &s : board) {
        cin >> s;
    }

    int surviving_sheeps = 0;
    int surviving_wolves = 0;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (board[x][y] == '#') continue;

            int sheeps_in_area = 0;
            int wolves_in_area = 0;
            queue<Point> bfs_que;

            if (board[x][y] == 'k') {
                sheeps_in_area++;
            }
            else if (board[x][y] == 'v') {
                wolves_in_area++;
            }

            board[x][y] = '#';
            bfs_que.emplace(x, y);

            while (!bfs_que.empty()) {
                Point now = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = now.x + dx[d];
                    int ny = now.y + dy[d];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (board[nx][ny] == '#') continue;

                    if (board[nx][ny] == 'k') {
                        sheeps_in_area++;
                    }
                    else if (board[nx][ny] == 'v') {
                        wolves_in_area++;
                    }

                    board[nx][ny] = '#';
                    bfs_que.emplace(nx, ny);
                }
            }

            if (sheeps_in_area > wolves_in_area) {
                surviving_sheeps += sheeps_in_area;
            }
            else {
                surviving_wolves += wolves_in_area;
            }
        }
    }

    cout << surviving_sheeps << ' ' << surviving_wolves << '\n';

    return 0;
}

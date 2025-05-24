// Solve 2025-01-09
// Update 2025-05-24

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int r, int c, vector<string>& board) {
    queue<Point> jihoon_que;
    queue<Point> fire_que;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (board[x][y] == 'J') {
                jihoon_que.emplace(x, y);
            }
            else if (board[x][y] == 'F') {
                fire_que.emplace(x, y);
            }
        }
    }

    int dist = 0;

    while (!jihoon_que.empty()) {
        dist++;
        int iter = fire_que.size();

        while (iter-- > 0) {
            Point cur = fire_que.front();
            fire_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

                if (board[nx][ny] != '.') continue;

                board[nx][ny] = 'F';
                fire_que.emplace(nx, ny);
            }
        }

        iter = jihoon_que.size();

        while (iter-- > 0) {
            Point cur = jihoon_que.front();
            jihoon_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) return dist;

                if (board[nx][ny] != '.') continue;

                board[nx][ny] = 'J';
                jihoon_que.emplace(nx, ny);
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    vector<string> board(r);

    for (string& row : board) {
        cin >> row;
    }

    int res = bfs(r, c, board);

    if (res == -1) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        cout << res << '\n';
    }

    return 0;
}

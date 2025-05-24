// Solve 2025-05-24

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

int h, w;
string board[1000];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int bfs() {
    queue<Point> person_bfs_que;
    queue<Point> fire_bfs_que;

    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            if (board[x][y] == '*') {
                fire_bfs_que.emplace(x, y);
            }
            else if (board[x][y] == '@') {
                person_bfs_que.emplace(x, y);
            }
        }
    }

    int dist = 0;

    while (!person_bfs_que.empty()) {
        dist++;
        int iter = fire_bfs_que.size();

        while (iter-- > 0) {
            Point cur_fire = fire_bfs_que.front();
            fire_bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur_fire.x + dx[d];
                int ny = cur_fire.y + dy[d];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

                if (board[nx][ny] != '.') continue;

                board[nx][ny] = '*';
                fire_bfs_que.emplace(nx, ny);
            }
        }

        iter = person_bfs_que.size();

        while (iter-- > 0) {
            Point cur_person = person_bfs_que.front();
            person_bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur_person.x + dx[d];
                int ny = cur_person.y + dy[d];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) return dist;

                if (board[nx][ny] != '.') continue;

                board[nx][ny] = '@';
                person_bfs_que.emplace(nx, ny);
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> w >> h;

        for (int x = 0; x < h; x++) {
            cin >> board[x];
        }

        int res = bfs();

        if (res == -1) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            cout << res << '\n';
        }
    }

    return 0;
}

// Solve 2022-12-10
// Update 2025-05-25

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
    int x;
    int y;
    int wall_cnt;

    Point(int x, int y, int wall_cnt) : x(x), y(y), wall_cnt(wall_cnt) {
    }
};

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
string board[1000];
bool visited[2][1000][1000];

int bfs(int n, int m) {
    queue<Point> bfs_que;
    bfs_que.emplace(-1, 0, 0);
    int dist = 0;

    while (!bfs_que.empty()) {
        int iter = bfs_que.size();
        dist++;

        while (iter-- > 0) {
            Point cur = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int nxt_wall_cnt = (board[nx][ny] == '1' ? cur.wall_cnt + 1 : cur.wall_cnt);

                if (nxt_wall_cnt > 1 || visited[nxt_wall_cnt][nx][ny]) continue;
                if (nx == n - 1 && ny == m - 1) return dist;

                visited[nxt_wall_cnt][nx][ny] = true;
                bfs_que.emplace(nx, ny, nxt_wall_cnt);
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    cout << bfs(n, m) << '\n';

    return 0;
}

// Solve 2022-12-10
// Update 2025-09-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Point{
    int z, x, y;

    Point(int z, int x, int y) : z(z), x(x), y(y) {}
};

int board[100][100][100];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};

int main() {
    FASTIO;

    int h, n, m;
    cin >> m >> n >> h;
    queue<Point> bfs_que;
    int not_ripe_cnt = 0;

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cin >> board[z][x][y];

                if (board[z][x][y] == 0) {
                    not_ripe_cnt++;
                }
                else if (board[z][x][y] == 1) {
                    bfs_que.emplace(z, x, y);
                }
            }
        }
    }

    int cur_day = 0;

    while (not_ripe_cnt > 0 && !bfs_que.empty()) {
        cur_day++;
        int iter = size(bfs_que);

        while (iter-- > 0) {
            Point cur = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 6; d++) {
                int nz = cur.z + dz[d];
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if (board[nz][nx][ny] == 0) {
                    board[nz][nx][ny] = 1;
                    bfs_que.emplace(nz, nx, ny);
                    not_ripe_cnt--;
                }
            }
        }
    }

    cout << (not_ripe_cnt > 0 ? -1 : cur_day) << '\n';
    return 0;
}

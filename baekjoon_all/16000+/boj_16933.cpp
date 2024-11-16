// Solve 2024-11-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

string board[1000];
int memo[1000][1000][11];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct Point{
    int x, y, w, dist;

    Point(int x, int y, int w) : x(x), y(y), w(w) {
    }
};

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int w = 0; w <= k; w++) {
                memo[x][y][w] = 100000000;
            }
        }
    }

    queue<Point> bfs_que;
    bfs_que.emplace(0, 0, 0);
    memo[0][0][0] = 1;

    while (!bfs_que.empty()) {
        Point cur = bfs_que.front();
        bfs_que.pop();

        int cur_dist = memo[cur.x][cur.y][cur.w];

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            int nw = 0;
            int ndist = 0;

            if (board[nx][ny] == '1') {
                nw = cur.w + 1;
                ndist = cur_dist % 2 == 1 ? cur_dist + 1 : cur_dist + 2;
            }
            else {
                nw = cur.w;
                ndist = cur_dist + 1;
            }

            if (nw <= k && ndist < memo[nx][ny][nw]) {
                memo[nx][ny][nw] = ndist;
                bfs_que.emplace(nx, ny, nw);
            }
        }
    }

    int ans = 100000000;

    for (int w = 0; w <= k; w++) {
        ans = min(ans, memo[n - 1][m - 1][w]);
    }

    println(ans == 100000000 ? -1 : ans);

    return 0;
}

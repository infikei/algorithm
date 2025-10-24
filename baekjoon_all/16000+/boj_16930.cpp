// Solve 2025-10-24

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
    int x, y, d;

    Point() {
    }

    Point(int x, int y) : x(x), y(y) {
    }

    Point(int x, int y, int d) : x(x), y(y), d(d) {
    }
};

string board[1000];
int min_dist[1000][1000];
bool visited[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    Point from, to;
    cin >> from.x >> from.y >> to.x >> to.y;
    from.x--;
    from.y--;
    to.x--;
    to.y--;

    memset(min_dist, 0x3f, sizeof min_dist);
    min_dist[from.x][from.y] = 0;
    visited[from.x][from.y] = true;
    queue<Point> que;

    for (int d = 0; d < 4; d++) {
        que.emplace(from.x, from.y, d);
    }

    while (!que.empty()) {
        Point cur = que.front();
        que.pop();
        int cur_dist = min_dist[cur.x][cur.y] + 1;

        int nx = cur.x;
        int ny = cur.y;

        for (int i = 1; i <= k; i++) {
            nx += dx[cur.d];
            ny += dy[cur.d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '#') break;
            if (cur_dist > min_dist[nx][ny]) break;
            if (cur_dist == min_dist[nx][ny]) continue;

            min_dist[nx][ny] = cur_dist;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                que.emplace(nx, ny, (cur.d + 1) % 4);
                que.emplace(nx, ny, (cur.d + 3) % 4);

                if (i == k) {
                    que.emplace(nx, ny, cur.d);
                }
            }
        }
    }

    int ans = min_dist[to.x][to.y];
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}

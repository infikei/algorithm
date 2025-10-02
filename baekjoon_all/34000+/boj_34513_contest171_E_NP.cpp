// Solve 2025-10-02

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

    Point(int x, int y, int d) : x(x), y(y), d(d) {
    }
};

string board[1000];
int dist[1000][1000][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    FASTIO;

    int n;
    cin >> n;
    memset(dist, 0x3f, sizeof dist);
    deque<Point> dque;
    Point white_king(0, 0, 0);

    for (int x = 0; x < n; x++) {
        cin >> board[x];

        for (int y = 0; y < n; y++) {
            if (board[x][y] == 'R') {
                dist[x][y][0] = 1;
                dist[x][y][1] = 1;
                dque.emplace_back(x, y, 0);
                dque.emplace_back(x, y, 1);
            }
            else if (board[x][y] == 'K') {
                white_king = {x, y, 0};
            }
        }
    }

    while (!dque.empty()) {
        Point cur = dque.front();
        dque.pop_front();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            int nd = d % 2;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 'B') continue;

            if (board[cur.x][cur.y] == 'W' || nd != cur.d) {
                int ndist = dist[cur.x][cur.y][cur.d] + 1;

                if (ndist < dist[nx][ny][nd]) {
                    dist[nx][ny][nd] = ndist;
                    dque.emplace_back(nx, ny, nd);
                }
            }
            else {
                int ndist = dist[cur.x][cur.y][cur.d];

                if (ndist < dist[nx][ny][nd]) {
                    dist[nx][ny][nd] = ndist;
                    dque.emplace_front(nx, ny, nd);
                }
            }
        }
    }

    int ans = min(dist[white_king.x][white_king.y][0], dist[white_king.x][white_king.y][1]);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}

// Solve 2025-11-25

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
    int x, y, h, d;

    Point(int x, int y, int h, int d) : x(x), y(y), h(h), d(d) {
    }
};

string board[500];
int visited[500][500];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FASTIO;

    int n, h, d;
    cin >> n >> h >> d;

    pii s;

    for (int x = 0; x < n; x++) {
        cin >> board[x];

        for (int y = 0; y < n; y++) {
            if (board[x][y] == 'S') {
                s = {x, y};
            }
        }
    }

    queue<Point> que;
    visited[s.first][s.second] = h;
    que.emplace(s.first, s.second, h, 0);
    int level = 0;

    while (!que.empty()) {
        level++;
        int iter = size(que);

        while (iter-- > 0) {
            Point cur = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if (board[nx][ny] == 'E') {
                    cout << level << '\n';
                    return 0;
                }

                int nh = cur.h;
                int nd = cur.d;

                if (board[nx][ny] == 'U') {
                    nd = d;
                }

                if (nd > 0) {
                    nd--;
                }
                else {
                    nh--;
                }

                if (nh == 0 || nh + nd <= visited[nx][ny]) continue;

                visited[nx][ny] = nh + nd;
                que.emplace(nx, ny, nh, nd);
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}

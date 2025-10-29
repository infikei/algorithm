// Solve 2025-10-29

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

bool board[1003][1003];
bool visited[1003][1003];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int sx, int sy, int tx, int ty) {
    if (tx == 0 && ty == 0) return 0;

    queue<pii> que;
    que.emplace(sx, sy);
    visited[sx][sy] = true;
    int dist = 0;

    while (!que.empty()) {
        dist++;
        int iter = size(que);

        while (iter-- > 0) {
            pii cur = que.front();
            que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                if (nx < 0 || nx > 1002 || ny < 0 || ny > 1002) continue;
                if (board[nx][ny] || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                que.emplace(nx, ny);

                if (nx == tx && ny == ty) {
                    return dist;
                }
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int x, y, n;
    cin >> x >> y >> n;
    x += 501;
    y += 501;

    while (n-- > 0) {
        int a, b;
        cin >> a >> b;
        board[a + 501][b + 501] = true;
    }

    cout << bfs(501, 501, x, y) << '\n';
    return 0;
}

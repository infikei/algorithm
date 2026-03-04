// Solve 2026-03-03

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

int board[100][100];
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    int cnt = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == 1 || visited[x][y]) continue;

            queue<pii> bfs_que;
            int area = 1;
            visited[x][y] = true;
            bfs_que.emplace(x, y);

            while (!bfs_que.empty()) {
                auto [xx, yy] = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = xx + dx[d];
                    int ny = yy + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == 1 || visited[nx][ny]) continue;

                    area++;
                    visited[nx][ny] = true;
                    bfs_que.emplace(nx, ny);
                }
            }

            cnt += (area - 1) / k + 1;
        }
    }

    if (cnt >= 1 && cnt <= m) {
        cout << "POSSIBLE" << '\n';
        cout << m - cnt << '\n';
    }
    else {
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}

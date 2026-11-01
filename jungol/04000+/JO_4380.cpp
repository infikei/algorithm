// Solve 2026-10-12

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

bool visited[1500][1500];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FASTIO;

    int n, m, p, k;
    cin >> n >> m >> p >> k;

    vector<pii> points;
    queue<pii> que;

    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        points.emplace_back(x, y);
        visited[x][y] = true;
        que.emplace(x, y);
    }

    for (int i = 0; i < k; i++) {
        int iter = size(que);

        while (iter-- > 0) {
            auto [x, y] = que.front();
            que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;
                que.emplace(nx, ny);
            }
        }
    }

    if (visited[0][0] || visited[n - 1][m - 1]) {
        cout << -1 << '\n';
        return 0;
    }

    queue<pii> que2;
    que2.emplace(0, 0);
    int dist = 0;

    while (!que2.empty()) {
        int iter = size(que2);
        dist++;

        while (iter-- > 0) {
            auto [x, y] = que2.front();
            que2.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;

                if (nx == n - 1 && ny == m - 1) {
                    cout << dist << '\n';
                    return 0;
                }

                visited[nx][ny] = true;
                que2.emplace(nx, ny);
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}

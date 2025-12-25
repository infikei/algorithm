// Solve 2025-12-24

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

bool visited[200][200];
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int main() {
    FASTIO;

    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 && c1 == c2) {
        cout << 0 << '\n';
        return 0;
    }

    queue<pii> que;
    que.emplace(r1, c1);
    visited[r1][c1] = true;
    int level = 0;

    while (!que.empty()) {
        level++;
        int iter = size(que);

        while (iter-- > 0) {
            auto [x, y] = que.front();
            que.pop();

            for (int d = 0; d < 6; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                if (nx == r2 && ny == c2) {
                    cout << level << '\n';
                    return 0;
                }

                visited[nx][ny] = true;
                que.emplace(nx, ny);
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}

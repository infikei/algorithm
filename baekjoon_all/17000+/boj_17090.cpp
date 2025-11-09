// Solve 2025-11-09

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

pii dxdy[128];
string board[500];
int memo[500][500];

int main() {
    FASTIO;

    dxdy['U'] = {-1, 0};
    dxdy['R'] = {0, 1};
    dxdy['D'] = {1, 0};
    dxdy['L'] = {0, -1};

    int n, m;
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    int cnt = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (memo[x][y] != 0) continue;

            int nx = x;
            int ny = y;
            vector<pii> path;

            while (nx >= 0 && nx < n && ny >= 0 && ny < m && memo[nx][ny] == 0) {
                memo[nx][ny] = -1;
                path.emplace_back(nx, ny);

                char d = board[nx][ny];
                auto [dx, dy] = dxdy[d];
                nx += dx;
                ny += dy;
            }

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || memo[nx][ny] == 1) {
                cnt += size(path);

                for (auto& p : path) {
                    memo[p.first][p.second] = 1;
                }
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}

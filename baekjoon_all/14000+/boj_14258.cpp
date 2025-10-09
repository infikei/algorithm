// Solve 2025-10-09

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
using piii = pair<int, pii>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int par[1000000];
int board[1000][1000];
bool visited[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int get_parent(int u) {
    if (par[u] < 0) return u;

    return par[u] = get_parent(par[u]);
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<piii> vec;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
            vec.push_back({board[x][y], {x, y}});
        }
    }

    sort(vec.begin(), vec.end(), greater<piii>());
    memset(par, -1, sizeof par);
    ll mx = 0;
    ll cur = 0;

    for (piii& p : vec) {
        int v = p.first;
        int x = p.second.first;
        int y = p.second.second;
        int xy = x * m + y;
        visited[x][y] = true;
        cur += board[x][y];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nxy = nx * m + ny;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !visited[nx][ny]) continue;

            int p1 = get_parent(xy);
            int p2 = get_parent(nxy);

            if (p1 != p2) {
                if (par[p1] > par[p2]) swap(p1, p2);

                par[p1] += par[p2];
                par[p2] = p1;
                cur -= board[p1 / m][p1 % m];
                cur -= board[p2 / m][p2 % m];
                board[p1 / m][p1 % m] ^= board[p2 / m][p2 % m];
                cur += board[p1 / m][p1 % m];
            }
        }

        mx = max(mx, cur);
    }

    cout << mx << '\n';
    return 0;
}

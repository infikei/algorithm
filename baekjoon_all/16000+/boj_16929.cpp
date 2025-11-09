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

int n, m;
string board[50];
bool visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool dfs(int x, int y, int px, int py) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (nx == px && ny == py) continue;
        if (board[nx][ny] != board[x][y]) continue;

        if (visited[nx][ny]) {
            return true;
        }

        visited[nx][ny] = true;

        if (dfs(nx, ny, x, y)) {
            return true;
        }
    }

    return false;
}

bool has_cycle() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (!visited[x][y] && dfs(x, y, -1, -1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    cout << (has_cycle() ? "Yes" : "No") << '\n';
    return 0;
}

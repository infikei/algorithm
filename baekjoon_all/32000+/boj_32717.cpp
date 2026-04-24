// Solve 2026-04-11

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

int board[1001][1001];
int tmp[2][1001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            cin >> board[x][y];
        }
    }

    int mx = -INF;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            tmp[1][y] = max(0, max(tmp[0][y], tmp[1][y - 1])) + board[x][y];
            mx = max(mx, tmp[1][y]);
        }

        swap(tmp[0], tmp[1]);
    }

    memset(tmp, 0, sizeof(tmp));

    for (int x = n; x >= 1; x--) {
        for (int y = 1; y <= m; y++) {
            tmp[1][y] = max(0, max(tmp[0][y], tmp[1][y - 1])) + board[x][y];
            mx = max(mx, tmp[1][y]);
        }

        swap(tmp[0], tmp[1]);
    }

    cout << mx << '\n';
    return 0;
}

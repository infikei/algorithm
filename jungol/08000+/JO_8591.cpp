// Solve 2026-06-14

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

ll row_prefix[801][801];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    ll mx = -10000;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            ll v;
            cin >> v;
            mx = max(mx, v);
            row_prefix[x][y] = row_prefix[x][y - 1] + v;
        }
    }

    for (int yl = 1; yl <= m; yl++) {
        for (int yh = yl; yh <= m; yh++) {
            ll cur = 0;

            for (int x = 1; x <= n; x++) {
                cur = max(cur, 0LL) + row_prefix[x][yh] - row_prefix[x][yl - 1];
                mx = max(mx, cur);
            }
        }
    }

    cout << mx << '\n';
    return 0;
}

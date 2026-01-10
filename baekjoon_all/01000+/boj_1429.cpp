// Solve 2026-01-04

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
string board[12];
int r_bit[12];
int c_bit[12];

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];

        for (int y = 0; y < m; y++) {
            if (board[x][y] == '1') {
                r_bit[x] |= (1 << y);
                c_bit[y] |= (1 << x);
            }
        }
    }

    {
        int b = 0;

        for (int x = 0; x < n; x++) {
            b |= r_bit[x];
        }

        if (b != (1 << m) - 1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    {
        int b = 0;

        for (int y = 0; y < m; y++) {
            b |= c_bit[y];
        }

        if (b != (1 << n) - 1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    int mn = INF;

    for (int b = 0; b < (1 << n); b++) {
        int c_mask_pre = 0;

        for (int x = 0; x < n; x++) {
            if (b & (1 << x)) {
                c_mask_pre |= r_bit[x];
            }
        }

        for (int v = 0; v < (1 << m); v++) {
            int c_mask = (c_mask_pre | v);
            int r_mask = b;

            for (int y = 0; y < m; y++) {
                if (v & (1 << y)) {
                    r_mask |= c_bit[y];
                }
            }

            int res = __builtin_popcount(b) + __builtin_popcount(v);
            res += n - __builtin_popcount(r_mask);
            res += m - __builtin_popcount(c_mask);
            mn = min(mn, res);
        }
    }

    cout << mn << '\n';
    return 0;
}

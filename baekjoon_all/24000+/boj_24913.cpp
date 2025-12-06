// Solve 2025-12-06

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

ll vote[100001];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    ll mine = 0;
    ll yours = 0;
    ll mx = 0;

    while (q-- > 0) {
        int cmd, x, y;
        cin >> cmd >> x >> y;

        if (cmd == 1) {
            if (y == n + 1) {
                mine += x;
            }
            else {
                yours += x;
                vote[y] += x;
                mx = max(mx, vote[y]);
            }
        }
        else {
            if (mx < mine + x && yours + y <= (mine + x - 1) * n) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}

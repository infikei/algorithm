// Solve 2025-11-15

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

int e[1 << 21];
int h[1 << 21];

int main() {
    FASTIO;

    int k;
    cin >> k;
    int n = 1 << (k + 1);

    for (int u = 2; u < n; u++) {
        cin >> e[u];
    }

    ll ans = 0;

    for (int u = n / 2 - 1; u >= 1; u--) {
        h[u] = max(h[u * 2] + e[u * 2], h[u * 2 + 1] + e[u * 2 + 1]);
        ans += h[u] - h[u * 2] + h[u] - h[u * 2 + 1];
    }

    cout << ans << '\n';
    return 0;
}

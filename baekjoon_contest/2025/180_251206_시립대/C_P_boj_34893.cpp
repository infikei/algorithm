// Solve 2025-12-06
// Update 2025-12-08

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

int main() {
    FASTIO;

    ll u, o, s;
    cin >> u >> o >> s;

    ll low = 0;
    ll high = u / 2;
    ll mx = 0;

    while (low <= high) {
        ll mid1 = (low * 2 + high) / 3;
        ll mid2 = (low + high * 2) / 3;

        ll mid1_val = min(o, min(u - mid1 * 2, s + mid1));
        ll mid2_val = min(o, min(u - mid2 * 2, s + mid2));

        if (mid1_val < mid2_val) {
            mx = max(mx, mid2_val);
            low = mid1 + 1;
        }
        else {
            mx = max(mx, mid1_val);
            high = mid2 - 1;
        }
    }

    cout << mx << '\n';
    return 0;
}

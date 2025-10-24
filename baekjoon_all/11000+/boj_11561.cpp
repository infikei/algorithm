// Solve 2025-10-24

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

    int t;
    cin >> t;

    while (t-- > 0) {
        ll n;
        cin >> n;

        ll low = 1;
        ll high = 150000000;
        ll mx = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll mid_val = mid * (mid + 1) / 2;

            if (mid_val <= n) {
                mx = max(mx, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << mx << '\n';
    }

    return 0;
}

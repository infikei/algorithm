// Solve 2025-10-15

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

ll a[1000000];

int main() {
    FASTIO;

    ll n, x;
    int m;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        ll mx = 0;
        ll low = 0;
        ll high = n;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll mid_val = a[i] * mid + a[m - 1] * (n - mid);

            if (mid_val <= x) {
                mx = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << mx << ' ';
        x -= a[i] * mx;
        n -= mx;
    }

    cout << '\n';
    return 0;
}

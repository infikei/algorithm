// Solve 2026-01-06

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

ll a[1000001];
ll d[1000001];

int main() {
    FASTIO;

    int n;
    ll k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        d[i] = a[i + 1] - a[i];
    }

    ll low = 0;
    ll high = 2000000000LL;
    ll mn = 2000000000LL;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll val = mid * mid - mid * (mid - 1) / 2;

        for (int i = 1; i < n && val < k; i++) {
            ll m = min(d[i], mid);
            val += m * mid - m * (m - 1) / 2;
        }

        if (val >= k) {
            mn = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << mn << '\n';
    return 0;
}

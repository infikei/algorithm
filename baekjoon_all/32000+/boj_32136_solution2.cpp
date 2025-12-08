// Solve 2025-12-07

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

ll a[300000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll low = 1;
    ll high = 150000000000LL;
    ll mn = high;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll l = 0;
        ll r = n - 1;

        for (int i = 0; i < n; i++) {
            ll d = mid / a[i];
            l = max(l, i - d);
            r = min(r, i + d);

            if (l > r) break;
        }

        if (l <= r) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << mn << '\n';
    return 0;
}

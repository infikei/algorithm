// Solve 2026-05-09

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

ll a[200001];

int main() {
    FASTIO;

    int n;
    ll k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll low = 0;
    ll high = 2000000000000000000LL;
    ll mx = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (mid > a[i]) {
                cnt += (mid - a[i] - 1) / i + 1;
            }

            if (cnt > k) break;
        }

        if (cnt <= k) {
            mx = max(mx, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << mx << '\n';
    return 0;
}

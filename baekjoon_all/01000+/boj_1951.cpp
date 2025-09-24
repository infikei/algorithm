// Solve 2025-09-23

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
const int MOD = 1234567;

int main() {
    FASTIO;

    ll n;
    cin >> n;
    ll ans = 0;

    for (int i = 1; i <= 10; i++) {
        ll range_begin = pow(10, i - 1);
        ll range_end = (ll) pow(10, i) - 1;
        ans += max(0LL, min(range_end, n) - range_begin + 1) * i;
        ans %= MOD;
    }

    cout << ans << '\n';
    return 0;
}

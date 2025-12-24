// Solve 2025-12-22

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
const ll MOD = 1000000007;

int main() {
    FASTIO;

    int h;
    ll x;
    cin >> h >> x;
    ll ans = 0;
    ll x_pow = 1;

    for (int i = 1; i <= h; i++) {
        ll c;
        cin >> c;
        x_pow = x_pow * x % MOD;
        ans = (ans + c * x_pow) % MOD;
    }

    cout << ans << '\n';
    return 0;
}

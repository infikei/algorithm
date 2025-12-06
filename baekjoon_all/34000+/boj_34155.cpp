// Solve 2025-12-02

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
const ll MOD = 998244353;

int main() {
    FASTIO;

    ll n;
    cin >> n;
    ll ans = 1;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if (i == a) ans = ans * (n - 1) % MOD;
        else ans = ans * (n - 2) % MOD;
    }

    cout << ans << '\n';
    return 0;
}

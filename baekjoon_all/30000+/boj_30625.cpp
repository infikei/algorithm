// Solve 2025-10-30

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

ll mod_pow(ll a, ll p) {
    ll ret = 1;

    while (p > 0) {
        if (p & 1) {
            ret = ret * a % MOD;
        }

        a = a * a % MOD;
        p >>= 1;
    }

    return ret;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    int f_cnt = 0; // front cnt
    int b_cnt = 0; // back cnt

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (b == 0) f_cnt++;
        else b_cnt++;
    }

    ll ans = mod_pow(m - 1, b_cnt);
    ans += f_cnt * mod_pow(m - 1, b_cnt + 1) % MOD;
    ans += b_cnt * mod_pow(m - 1, b_cnt - 1) % MOD;
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}

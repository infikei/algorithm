// Solve 2023-03-12
// Update 2025-10-06

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

ll mod_inv(ll a) {
    // a ^ -1 = a ^ (p - 2) (mod p) 이용
    return mod_pow(a, MOD - 2);
}

ll s(int k, int n) {
    k++;
    ll lower = 1;
    ll upper = 1;

    for (int i = 1, ii = n; i <= k; i++, ii++) {
        lower = lower * i % MOD;
        upper = upper * ii % MOD;
    }

    // upper / lower 계산
    return upper * mod_inv(lower) % MOD;
}

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;

    cout << s(k, n) << '\n';
    return 0;
}

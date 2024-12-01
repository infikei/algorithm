// Solve 2024-11-30
// Update 2024-12-01

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;
const ll MOD = 1000000007;

ll get_mod_pow(ll a, ll p, ll mod) {
    ll res = 1;
    ll ap = a;

    while (p > 0) {
        if (p % 2 == 1) {
            res = res * ap % mod;
        }

        ap = ap * ap % mod;
        p >>= 1;
    }

    return res;
}

ll get_mod_inv(ll a, ll mod) {
    return get_mod_pow(a, mod - 2, mod);
}

ll get_mod_comb(ll n, ll r, ll mod) {
    ll res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i) % mod;
    }

    ll divisor = 1;

    for (int i = 1; i <= r; i++) {
        divisor = divisor * i % mod;
    }

    return res * get_mod_inv(divisor, mod) % mod;
}

int main() {
    FASTIO;

    int lv;
    cin >> lv;

    if (lv <= 5) {
        // 4의 lv제곱을 계산한다.
        int ans = (1 << (lv * 2));
        println(ans);
    }
    else {
        // 8의 lv제곱을 계산한다.
        ll ans = get_mod_pow(8, lv, MOD);

        // lvC0 + lvC1 + ... + lvC6을 계산한다.
        ll comb_sum = 1 + lv;

        for (int i = 2; i <= 6; i++) {
            comb_sum = comb_sum + get_mod_comb(lv, i, MOD);
        }

        // 위에서 구한 두 값을 곱한다.
        ans = ans * comb_sum % MOD;
        println(ans);
    }

    return 0;
}

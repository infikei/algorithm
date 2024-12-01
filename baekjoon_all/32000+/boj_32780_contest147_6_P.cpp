// Solve 2024-11-30

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

ll get_pow_with_mod(ll a, ll p, ll mod) {
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

ll get_comb_with_mod(ll n, ll c, ll mod) {
    ll res = 1;

    for (int i = 0; i < c; i++) {
        res = res * (n - i) % mod;
    }

    ll inv = 1;

    for (int i = 1; i <= c; i++) {
        inv = inv * i % mod;
    }

    inv = get_pow_with_mod(inv, mod - 2, mod);
    return res * inv % mod;
}

int main() {
    FASTIO;

    int lv;
    cin >> lv;

    if (lv <= 5) {
        ll ans = get_pow_with_mod(4, lv, MOD);
        println(ans);
    }
    else {
        ll ans = get_pow_with_mod(8, lv, MOD);
        ll comb_sum = 1;

        for (int i = 1; i <= 6; i++) {
            comb_sum = comb_sum + get_comb_with_mod(lv, i, MOD);
        }

        ans = ans * comb_sum % MOD;
        println(ans);
    }

    return 0;
}

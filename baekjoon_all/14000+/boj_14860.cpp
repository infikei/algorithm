// Solve 2025-08-18

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
const int MAX_OF_N_AND_M = 15000000;

bool prime_sieve[MAX_OF_N_AND_M + 1];
vector<ll> primes;

ll mod_pow(ll a, ll p) {
    ll res = 1;

    while (p > 0) {
        if (p & 1) {
            res = res * a % MOD;
        }

        a = a * a % MOD;
        p >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    memset(prime_sieve, true, sizeof prime_sieve);
    prime_sieve[1] = false;

    for (int i = 2; i <= MAX_OF_N_AND_M; i++) {
        if (!prime_sieve[i]) continue;

        primes.push_back(i);

        for (int j = i + i; j <= MAX_OF_N_AND_M; j += i) {
            prime_sieve[j] = false;
        }
    }

    ll n, m;
    cin >> n >> m;
    ll ans = 1;

    for (ll& p : primes) {
        ll pp = p;

        while (pp <= min(n, m)) {
            ll cnt = (n / pp) * (m / pp);
            ans = ans * mod_pow(p, cnt) % MOD;
            pp *= p;
        }
    }

    cout << ans << '\n';
    return 0;
}

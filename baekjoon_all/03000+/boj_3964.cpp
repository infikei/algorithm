// Solve 2025-11-11

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

bool sieve[1000000];
vector<int> primes;

void create_sieve() {
    memset(sieve, true, sizeof sieve);

    for (int i = 2; i * i < 1000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);

            for (int j = i * i; j < 1000000; j += i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = primes.back() + 1; i < 1000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

void get_prime_factorization(ll k, vector<pll>& ret) {
    for (int i = 0; i < size(primes) && (ll) primes[i] * primes[i] <= k; i++) {
        ll p = primes[i];
        ll cnt = 0;

        while (k % p == 0) {
            cnt++;
            k /= p;
        }

        if (cnt >= 1) {
            ret.emplace_back(p, cnt);
        }
    }

    if (k > 1) {
        ret.emplace_back(k, 1);
    }
}

ll count_prime_in_factorial(ll n, ll p) {
    ll cnt = 0;

    while (n > 0) {
        n /= p;
        cnt += n;
    }

    return cnt;
}

int main() {
    FASTIO;

    create_sieve();

    int t;
    cin >> t;

    while (t-- > 0) {
        ll n, k;
        cin >> n >> k;

        vector<pll> prime_factor_counts;
        get_prime_factorization(k, prime_factor_counts);
        ll mn = LLINF;

        for (auto [p, c] : prime_factor_counts) {
            ll cnt = count_prime_in_factorial(n, p);
            mn = min(mn, cnt / c);
        }

        cout << mn << '\n';
    }

    return 0;
}

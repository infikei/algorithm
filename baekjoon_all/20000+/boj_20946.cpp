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
const int MOD = 1000000007;

bool sieve[1000000];
vector<int> primes;

void create_sieve() {
    for (int i = 2; i * i < 1000000; i++) {
        if (!sieve[i]) {
            primes.push_back(i);

            for (int j = i * i; j < 1000000; j += i) {
                sieve[j] = true;
            }
        }
    }

    for (int i = primes.back() + 1; i < 1000000; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    FASTIO;

    create_sieve();

    ll n;
    cin >> n;
    vector<ll> prime_divisors;

    for (int p : primes) {
        while (n % p == 0) {
            prime_divisors.push_back(p);
            n /= p;
        }
    }

    if (n > 1) {
        prime_divisors.push_back(n);
    }

    int n_divisors = size(prime_divisors);

    if (n_divisors <= 1) {
        cout << -1 << '\n';
    }
    else if (n_divisors % 2 == 1) {
        for (int i = 0; i + 3 < n_divisors; i += 2) {
            cout << prime_divisors[i] * prime_divisors[i + 1] << ' ';
        }

        cout << prime_divisors[n_divisors - 3] * prime_divisors[n_divisors - 2] * prime_divisors[n_divisors - 1] << '\n';
    }
    else {
        for (int i = 0; i < n_divisors; i += 2) {
            cout << prime_divisors[i] * prime_divisors[i + 1] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

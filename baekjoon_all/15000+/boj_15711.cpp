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
const int MOD = 1000000007;

bool sieve[2000000];
vector<int> primes;

void create_sieve() {
    memset(sieve, true, sizeof sieve);
    sieve[1] = false;

    for (int i = 2; i * i < 2000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);

            for (int j = i * i; j < 2000000; j += i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = primes.back() + 1; i < 2000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

bool is_prime(ll k) {
    if (k <= 1) return false;

    int sqrt_k = sqrt(k);

    for (int i = 0; i < size(primes) && primes[i] <= sqrt_k; i++) {
        if (k % primes[i] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    create_sieve();

    int t;
    cin >> t;

    while (t-- > 0) {
        ll a, b;
        cin >> a >> b;
        a += b;

        if (a <= 3) {
            cout << "NO" << '\n';
        }
        else if (a % 2 == 0) {
            cout << "YES" << '\n';
        }
        else {
            if (is_prime(a - 2)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}

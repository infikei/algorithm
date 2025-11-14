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

int main() {
    FASTIO;

    ll k;
    cin >> k;

    vector<ll> prime_divisors;

    for (ll i = 2; i * i <= k; i++) {
        while (k % i == 0) {
            prime_divisors.push_back(i);
            k /= i;
        }
    }

    if (k != 1) prime_divisors.push_back(k);

    cout << size(prime_divisors) << '\n';

    for (ll p : prime_divisors) {
        cout << p << ' ';
    }

    cout << '\n';
    return 0;
}

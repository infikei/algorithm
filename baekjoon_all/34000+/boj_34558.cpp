// Solve 2025-10-08

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

bool sieve[1000001];

int main() {
    FASTIO;

    memset(sieve, true, sizeof sieve);
    sieve[1] = false;
    vector<int> primes;

    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);

            for (int j = i * 2; j <= 1000000; j += i) {
                sieve[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    while (n-- > 0) {
        int a, b;
        cin >> a >> b;

        int idx1 = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
        int idx2 = upper_bound(primes.begin(), primes.end(), b) - primes.begin();
        idx2--;

        if (idx1 > idx2 || (idx2 - idx1) % 2 == 1) {
            cout << -1 << '\n';
        }
        else {
            cout << primes[(idx1 + idx2) / 2] << '\n';
        }
    }

    return 0;
}

// Solve 2026-02-01

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

bool sieve[1000];

void find_three_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) continue;

        for (int j = i; j <= n - i; j++) {
            if (sieve[j] || sieve[n - i - j]) continue;

            vector<int> v = {i, j, n - i - j};
            sort(v.begin(), v.end());
            cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}

int main() {
    FASTIO;

    sieve[0] = true;
    sieve[1] = true;

    for (int i = 2; i * i < 1000; i++) {
        if (sieve[i]) continue;

        for (int j = i * i; j < 1000; j += i) {
            sieve[j] = true;
        }
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        find_three_primes(n);
    }

    return 0;
}

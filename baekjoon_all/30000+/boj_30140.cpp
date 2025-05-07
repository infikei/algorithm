// Solve 2025-05-05

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> get_primes(int x) {
    vector<int> primes;
    vector<bool> sieve(x + 1);

    for (int i = 2; i <= x; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (int j = i + i; j <= x; j += i) {
            sieve[j] = true;
        }
    }

    return primes;
}

int main() {
    FASTIO;

    vector<int> primes = get_primes(1000);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int res = 1;

        for (int &p : primes) {
            int cnt = 0;

            while (n % p == 0) {
                n /= p;
                cnt++;
            }

            res = max(res, cnt);
        }

        cout << res << '\n';
    }

    return 0;
}

// Solve 2025-10-02

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

bool sieve[1001];
vector<int> primes;

int count_prime_dividers(int k) {
    int ret = 0;

    for (int& p : primes) {
        while (k % p == 0) {
            k /= p;
            ret++;
        }
    }

    if (k > 1) {
        ret++;
    }

    return ret;
}

bool is_underprime(int k) {
    return sieve[count_prime_dividers(k)];
}

int main() {
    FASTIO;

    memset(sieve, true, sizeof sieve);
    sieve[1] = false;
    

    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) {
            primes.push_back(i);

            for (int j = i * 2; j <= 1000; j += i) {
                sieve[j] = false;
            }
        }
    }

    int a, b;
    cin >> a >> b;
    int underprime_cnt = 0;

    for (int i = a; i <= b; i++) {
        if (is_underprime(i)) {
            underprime_cnt++;
        }
    }

    cout << underprime_cnt << '\n';
    return 0;
}

// Solve 2025-02-21

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

bool sieve[1000000];
vector<int> primes;

void find_primes() {
    for (int i = 2; i < 1000000; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (int j = i * 2; j < 1000000; j += i) {
            sieve[j] = true;
        }
    }
}

int main() {
    FASTIO;

    find_primes();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll s;
        cin >> s;

        bool divided_by_prime = false;

        for (int &p : primes) {
            if (s % p == 0) {
                divided_by_prime = true;
                break;
            }
        }

        if (divided_by_prime) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}

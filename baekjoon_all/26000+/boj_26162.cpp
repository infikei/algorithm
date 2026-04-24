// Solve 2026-04-16

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

bool sieve[120];

void create_sieve() {
    memset(sieve, true, sizeof(sieve));

    for (int i = 2; i * i < 120; i++) {
        if (sieve[i]) {
            for (int j = i * i; j < 120; j += i) {
                sieve[j] = false;
            }
        }
    }
}

bool is_sum_of_two_primes(int a) {
    int i = 2;
    int j = a - 2;

    while (i <= j) {
        if (sieve[i] && sieve[j]) {
            return true;
        }

        i++;
        j--;
    }

    return false;
}

int main() {
    FASTIO;

    create_sieve();

    int n;
    cin >> n;

    while (n-- > 0) {
        int a;
        cin >> a;

        cout << (is_sum_of_two_primes(a) ? "Yes" : "No") << '\n';
    }

    return 0;
}

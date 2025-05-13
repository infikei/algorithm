// Solve 2023-12-11
// Update 2025-05-13

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

int main() {
    FASTIO;

    vector<bool> sieve(10001, true);
    sieve[1] = false;

    for (int i = 2; i < 10001; i++) {
        if (!sieve[i]) continue;

        for (int j = i + i; j < 10001; j += i) {
            sieve[j] = false;
        }
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for (int i = n / 2; i >= 2; i--) {
            if (sieve[i] && sieve[n - i]) {
                cout << i << ' ' << n - i << '\n';
                break;
            }
        }
    }

    return 0;
}

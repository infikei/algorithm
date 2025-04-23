// Solve 2025-04-22

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

int sieve[100001];

int main() {
    FASTIO;

    for (int i = 2; i <= 100000; i++) {
        if (sieve[i] > 0) continue;

        for (int j = i; j <= 100000; j += i) {
            sieve[j] = i;
        }
    }

    int n, k;
    cin >> n >> k;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (sieve[i] <= k) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}

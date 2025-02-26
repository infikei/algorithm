// Solve 2023-04-18
// Update 2025-02-26

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

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    ll p10 = 10;
    ll p10_mod_k = 10;

    for (int i = 1; i <= n; i++) {
        if (i >= p10) {
            p10 *= 10;
            p10_mod_k = p10 % k;
        }

        ans = (ans * p10_mod_k + i) % k;
    }

    cout << ans << '\n';

    return 0;
}

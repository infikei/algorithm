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

    string s;
    cin >> s;

    const ll MOD = 1000000007;
    ll ans = 0;

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        if (*it == 'O') {
            ans = ((ans << 1) | 1) % MOD;
        }
        else {
            ans = (ans << 1) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}

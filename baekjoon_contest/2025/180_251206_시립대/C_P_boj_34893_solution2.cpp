// Solve 2025-12-06
// Update 2025-12-08

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

int main() {
    FASTIO;

    ll u, o, s;
    cin >> u >> o >> s;

    ll cnt1 = min(u, min(o, s));
    u -= cnt1;
    o -= cnt1;
    s -= cnt1;

    ll cnt2 = 0;

    if (s == 0) {
        cnt2 = min(u / 3, o);
    }

    cout << cnt1 + cnt2 << '\n';
    return 0;
}

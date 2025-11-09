// Solve 2025-11-08

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

    ll r, s;
    int n;
    cin >> r >> s >> n;

    if (r == 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        r = (r - a % s + s) % s;

        if (r == 0) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}

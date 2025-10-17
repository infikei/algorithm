// Solve 2025-10-17

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

ll get_gcd(ll a, ll b) {
    while (b > 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ll get_lcm(ll a, ll b) {
    return a / get_gcd(a, b) * b;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        ll max_lcm = 0;

        for (int i = max(1, n - 3); i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ll lcm2 = get_lcm(j, i);

                for (int k = j + 1; k <= n; k++) {
                    ll lcm3 = get_lcm(lcm2, k);
                    max_lcm = max(max_lcm, lcm3);
                }
            }
        }

        cout << max_lcm << '\n';
    }

    return 0;
}

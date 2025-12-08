// Solve 2025-12-08

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

ll my_gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FASTIO;

    ll a, d;
    int q;
    cin >> a >> d >> q;

    while (q-- > 0) {
        int cmd, l, r;
        cin >> cmd >> l >> r;

        if (cmd == 1) {
            ll left = a + (l - 1) * d;
            ll right = a + (r - 1) * d;

            ll ans = (left + right) * (r - l + 1) / 2;
            cout << ans << '\n';
        }
        else {
            if (d == 0) {
                cout << a << '\n';
            }
            else if (l == r) {
                cout << a + (l - 1) * d << '\n';
            }
            else {
                cout << my_gcd(a, d) << '\n';
            }
        }
    }

    return 0;
}

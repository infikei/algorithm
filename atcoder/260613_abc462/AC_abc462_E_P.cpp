// Solve 2026-06-13

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

    int t;
    cin >> t;

    while (t-- > 0) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        x = abs(x);
        y = abs(y);

        if (a == b) {
            cout << (x + y) * a << '\n';
            continue;
        }

        if (a > b) {
            swap(a, b);
            swap(x, y);
        }

        ll z = min(x, y);
        x -= z;
        y -= z;
        ll ans = z * 2 * a;

        if (x > 0) {
            if (b > 3 * a) {
                y = x / 2 * 2;
            }
        }
        else if (y > 0) {
            if (b > 3 * a) {
                x = (y + 1) / 2 * 2;
            }
        }

        z = min(x, y);
        x -= z;
        y -= z;
        ans += z * 2 * a;

        if (x > 0) {
            ans += (x + 1) / 2 * a + x / 2 * b;
        }
        else if (y > 0) {
            ans += y / 2 * a + (y + 1) / 2 * b;
        }

        cout << ans << '\n';
    }

    return 0;
}

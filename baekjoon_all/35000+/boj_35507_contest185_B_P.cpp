// Solve 2026-04-26

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
        int n;
        cin >> n;

        ll prv_a = 0, prv_b = 0, prv_c = 0, day = 0;
        bool ans = true;

        for (int i = 1; i <= n; i++) {
            ll a, b, c, p;
            cin >> a >> b >> c >> p;

            a = max(prv_a, a);
            b = max(prv_b, b);
            c = max(prv_c, c);

            day += (a - prv_a) + (b - prv_b) + (c - prv_c) + 1;

            if (day > p) {
                ans = false;
            }

            prv_a = a;
            prv_b = b;
            prv_c = c;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}

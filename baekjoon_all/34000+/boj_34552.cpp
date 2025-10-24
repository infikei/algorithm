// Solve 2025-10-23

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

int m[11];

int main() {
    FASTIO;

    for (int i = 0; i < 11; i++) {
        cin >> m[i];
    }

    int n;
    cin >> n;
    int ans = 0;

    while (n-- > 0) {
        int b, s;
        double l;
        cin >> b >> l >> s;

        if (l >= 2.0 && s >= 17) {
            ans += m[b];
        }
    }

    cout << ans << '\n';
    return 0;
}

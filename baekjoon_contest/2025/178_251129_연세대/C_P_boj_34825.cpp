// Solve 2025-11-29

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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(a - c) % 2 != abs(b - d) % 2) {
        cout << -1 << '\n';
        return 0;
    }

    ll x = (a + c) / 2;
    ll y = (b + d) / 2;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            ll nx = x + dx;
            ll ny = y + dy;

            if (abs(nx) > 1000000000 || abs(ny) > 1000000000) continue;

            if (abs(a - nx) + abs(b - ny) == abs(c - nx) + abs(d - ny)) {
                cout << nx << ' ' << ny << '\n';
                return 0;
            }
        }
    }

    return 0;
}

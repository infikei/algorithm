// Solve 2025-12-06

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

struct Pair{
    int x, y, z;

    Pair(int x, int y, int z) : x(x), y(y), z(z) {
    }
};

int main() {
    FASTIO;

    ll n, a, b, c, d, e, f, g, h;
    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h;

    vector<Pair> ans;

    for (ll x = n; x >= 0; x--) {
        ll ax = a * x;
        ll ex = e * x;

        for (ll y = n - x; y >= 0; y--) {
            ll z = n - x - y;

            if (ax + b * y + c * z == d && ex + f * y + g * z == h) {
                ans.emplace_back(x, y, z);

                if (size(ans) >= 2) {
                    cout << 1 << '\n';
                    return 0;
                }
            }
        }
    }

    if (ans.empty()) {
        cout << 2 << '\n';
    }
    else {
        auto [x, y, z] = ans[0];
        cout << 0 << '\n';
        cout << x << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}

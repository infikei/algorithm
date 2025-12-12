// Solve 2025-12-11

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

struct Town{
    int x;
    ll a;
    ll xa;

    Town(int x, int a) : x(x), a(a) {
        xa = (ll) x * a;
    }

    bool operator<(const Town& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return a < rhs.a;
    }
};

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    vector<Town> town;

    for (int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;
        town.emplace_back(x, a);
    }

    sort(town.begin(), town.end());

    for (int i = 1; i < n; i++) {
        town[i].a += town[i - 1].a;
        town[i].xa += town[i - 1].xa;
    }

    while (q-- > 0) {
        int y;
        cin >> y;

        Town tmp = {y, 0};
        int idx = lower_bound(town.begin(), town.end(), tmp) - town.begin();

        ll ans = 0;

        if (idx < n) {
            ans += town[n - 1].xa;
            ans -= town[n - 1].a * y;

            if (idx >= 1) {
                ans -= town[idx - 1].xa;
                ans += town[idx - 1].a * y;
            }
        }

        if (idx >= 1) {
            ans -= town[idx - 1].xa;
            ans += town[idx - 1].a * y;
        }

        cout << ans << '\n';
    }

    return 0;
}

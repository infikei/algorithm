// Solve 2025-11-04

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
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

pll reduce_frac(pll a) {
    ll gcd = get_gcd(a.first, a.second);
    return {a.first / gcd, a.second / gcd};
}

pll add_frac(pll& a, pll& b) {
    return reduce_frac({a.first * b.second + b.first * a.second, a.second * b.second});
}

int main() {
    FASTIO;

    int n;
    ll m;
    cin >> n >> m;

    vector<pll> vec;

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        vec.emplace_back(v, w);
    }

    auto cmp = [](pll& a, pll& b) {
        return a.first * b.second > b.first * a.second;
    };

    sort(vec.begin(), vec.end(), cmp);
    pll ans(0, 1);

    for (int i = 0; i < n; i++) {
        if (m <= vec[i].second) {
            pll cur = {vec[i].first * m, vec[i].second};
            ans = add_frac(ans, cur);
            break;
        }

        m -= vec[i].second;
        ans.first += vec[i].first;
    }

    cout << ans.first << '/' << ans.second << '\n';
    return 0;
}

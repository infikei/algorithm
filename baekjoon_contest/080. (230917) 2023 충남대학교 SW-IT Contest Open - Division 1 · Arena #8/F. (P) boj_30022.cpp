// Solve 2023-09-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    vector<ll> vec;

    for (int i = 0; i < n; i++) {
        ll p, q;
        cin >> p >> q;

        ans += min(p, q);
        vec.push_back(p - q);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < a; i++) {
        ans += max(0ll, vec[i]);
    }

    for (int i = a; i < n; i++) {
        ans -= min(0ll, vec[i]);
    }

    cout << ans << '\n';

    return 0;
}

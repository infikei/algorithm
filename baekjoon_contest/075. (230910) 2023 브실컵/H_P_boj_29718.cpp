// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<ll> vec(m + 1, 0);

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            ll x;
            cin >> x;

            vec[col] += x;
        }
    }

    for (int col = 1; col <= m; col++) {
        vec[col] += vec[col - 1];
    }

    int a;
    cin >> a;

    ll ans = 0;

    for (int col = a; col <= m; col++) {
        ans = max(ans, vec[col] - vec[col - a]);
    }

    cout << ans << '\n';

    return 0;
}

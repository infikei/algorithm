// Solve 2023-12-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        ll n, m;
        cin >> n >> m;

        ll ans = (m + n) * (m - n + 1) / 2;

        if (ti >= 2) cout << '\n';

        cout << "Scenario #" << ti << ":\n" << ans << '\n';
    }

    return 0;
}

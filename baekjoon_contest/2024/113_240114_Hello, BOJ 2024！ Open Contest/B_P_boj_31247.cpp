// Solve 2024-01-14

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

    for (int ti = 0; ti < t; ti++) {
        ll n, k;
        cin >> n >> k;

        if (k >= 60) {
            cout << 0 << '\n';
            continue;
        }

        ll ans = n / (1ll << k) - n / (1ll << (k + 1));
        cout << ans << '\n';
    }

    return 0;
}

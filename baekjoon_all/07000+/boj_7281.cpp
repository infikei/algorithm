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

    int n;
    cin >> n;

    int ans = 0;
    int t0, m0;
    cin >> t0 >> m0;

    for (int i = 1; i < n; i++) {
        int t, m;
        cin >> t >> m;

        if (m == 1) {
            ans = max(ans, t - t0);
            t0 = t;
        }
    }

    cout << ans << '\n';

    return 0;
}

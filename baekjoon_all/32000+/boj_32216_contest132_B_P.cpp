// Solve 2024-09-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k, t0;
    cin >> n >> k >> t0;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int di;
        cin >> di;

        ans += di;
    }

    cout << ans << '\n';

    return 0;
}

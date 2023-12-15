// Solve 2022-10-22
// Update 2023-12-15

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
        int n, x0;
        cin >> n >> x0;

        int ans = x0;
        int cur = x0;

        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;

            cur = max(cur, 0) + x;
            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}

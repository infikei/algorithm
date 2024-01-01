// Solve 2023-12-30

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
        int m;
        cin >> m;

        int cur = 0;
        int ans = 0;

        for (int mi = 0; mi < m; mi++) {
            int p1, p2;
            cin >> p1 >> p2;

            cur += p1 - p2;
            ans = min(ans, cur);
        }

        cout << -ans << '\n';
    }

    return 0;
}

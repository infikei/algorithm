// Solve 2024-01-04

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
        int n, w, e;
        cin >> n >> w >> e;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            ans += max(a * w + c * e, b * w + d * e);
        }

        if (ti >= 2) cout << '\n';

        cout << "Data Set " << ti << ":\n";
        cout << ans << '\n';
    }

    return 0;
}

// Solve 2023-09-27

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
        if (ti >= 2) cout << '\n';

        int n, v, t;
        cin >> n >> v >> t;

        int vt = v * t, ans = 0;

        for (int i = 0; i < n; i++) {
            int d, value;
            cin >> d >> value;

            if (d <= vt) ans += value;
        }

        cout << "Data Set " << ti << ":\n" << ans << '\n';
    }

    return 0;
}

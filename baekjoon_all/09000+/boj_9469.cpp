// Solve 2023-04-21
// Update 2023-12-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(6);

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int p;
        double d, a, b, f;
        cin >> p >> d >> a >> b >> f;

        double ans = d * f / (a + b);

        cout << p << ' ' << ans << '\n';
    }

    return 0;
}

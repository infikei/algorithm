// Solve 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x1, x2;
    cin >> x1 >> x2;

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int ans = a / 3 * (x2 * x2 * x2 - x1 * x1 * x1) + (b - d) / 2 * (x2 * x2 - x1 * x1) + (c - e) * (x2 - x1);
    cout << ans << '\n';

    return 0;
}

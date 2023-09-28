// Solve 2023-09-28

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

    int a, b, c;
    cin >> a >> b >> c;

    double ans = 0;
    ans += a * 0.229 * 0.324 * 2;
    ans += b * 0.297 * 0.42 * 2;
    ans += c * 0.21 * 0.297;

    cout << ans << '\n';

    return 0;
}

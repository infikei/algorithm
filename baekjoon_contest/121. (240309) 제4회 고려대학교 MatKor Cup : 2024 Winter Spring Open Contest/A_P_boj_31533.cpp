// Solve 2024-03-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;
    SETPRECISION(7);

    int a, m, n;
    cin >> a >> m >> n;

    double ans = min({ 2 * m, 2 * n, max(m, a * n), max(a * m, n) });
    ans /= a;
    cout << ans << '\n';

    return 0;
}

// Solve 2022-12-24
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int b, c, a1, a2;
    cin >> b >> c >> a1 >> a2;

    double b2 = (double)b / 2;
    double ans = b2 + sqrt(b2 * b2 + c);

    SETPRECISION(9);
    cout << ans << '\n';

    return 0;
}

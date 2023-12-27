// Solve 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = M_PI;

int main() {
    FASTIO;

    SETPRECISION(12);

    ll a;
    cin >> a;

    double r = sqrt(a / PI);
    double ans = r * 2 + 2;
    ans *= ans;

    cout << ans << '\n';

    return 0;
}

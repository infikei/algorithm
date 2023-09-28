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

    SETPRECISION(2);

    int k;
    cin >> k;

    double ans;

    if (k < 7500) ans = 100;
    else if (k > 197500) ans = 2000;
    else ans = 25 + k * 0.01;

    cout << ans << '\n';

    return 0;
}

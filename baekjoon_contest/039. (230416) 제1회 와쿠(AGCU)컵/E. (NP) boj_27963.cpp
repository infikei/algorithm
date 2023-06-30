// Solve 2023-06-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int d1, d2, x;
    cin >> d1 >> d2 >> x;

    if (d1 < d2) {
        swap(d1, d2);
    }

    double ans = (double)100 * d1 * d2 / (d2 * x + d1 * (100 - x));
    SETPRECISION(14);
    cout << ans << '\n';

    return 0;
}

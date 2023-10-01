// Solve 2023-09-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(9);

    int n;
    cin >> n;

    double ans3 = 0;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;

        ans3 += x * x * x;
    }

    double ans = cbrt(ans3);

    cout << ans << '\n';

    return 0;
}

// Solve 2023-09-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int m, n;
    cin >> m >> n;

    int ans;

    if (m == 1) {
        ans = n;
    }
    else if (n == 1) {
        ans = m;
    }
    else {
        ans = (m + n) * 2 - 4;
    }

    cout << ans << '\n';

    return 0;
}

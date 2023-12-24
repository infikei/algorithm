// Solve 2023-11-12
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    int l0, r0;
    cin >> l0 >> r0;

    int ans = 0;

    if (l0 == r0 && l0 != 0) ans++;

    for (int i = 1; i < t; i++) {
        int l, r;
        cin >> l >> r;

        if (l == l0 && l != 0) ans++;
        if (r == r0 && r != 0) ans++;
        if (l == r && l != 0) ans++;

        l0 = l; r0 = r;
    }

    cout << ans << '\n';

    return 0;
}

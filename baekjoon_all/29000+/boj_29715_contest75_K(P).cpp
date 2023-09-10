// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int m0 = 0, m1 = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 0) m0++;
        else m1++;
    }

    int cnt = 1;

    for (int i = 0, ii = n - m1, ie = m0; i < ie; i++, ii--) {
        cnt *= ii;
    }

    for (int i = 0, ii = 9 - m, ie = n - m; i < ie; i++, ii--) {
        cnt *= ii;
    }

    int ans = cnt * x + (cnt - 1) / 3 * y;

    cout << ans << '\n';

    return 0;
}

// Solve 2024-01-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int c, w, l, p;
        cin >> c >> w >> l >> p;

        if (c == 0 && w == 0 && l == 0 && p == 0) break;

        int wlp = w * l * p;
        int ans = c;

        for (int i = 1; i < wlp; i++) {
            ans *= c;
        }

        cout << ans << '\n';
    }


    return 0;
}

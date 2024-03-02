// Solve 2024-03-01

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

    for (int ti = 1; ti <= t; ti++) {
        int w, h, a, b;
        cin >> w >> h >> a >> b;

        int ans = 0;

        while (w > 0 && h > 0) {
            if (w < a || h < b) {
                ans += w * h;
                break;
            }

            ans += a * h + b * w - a * b;
            w -= a * 2;
            h -= b * 2;
        }

        cout << ans << '\n';
    }

    return 0;
}

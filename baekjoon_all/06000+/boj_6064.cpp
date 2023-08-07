// Solve 2023-06-01
// Update 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc_gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return calc_gcd(b, r);
}

int calc_lcm(int a, int b) {
    int gcd = calc_gcd(a, b);
    return a / gcd * b;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int lcm_mn = calc_lcm(m, n);
        int ans = -1;

        for (int k = x; k <= lcm_mn; k += m) {
            int r = k % n;
            if (r == 0) r = n;

            if (r == y) {
                ans = k;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

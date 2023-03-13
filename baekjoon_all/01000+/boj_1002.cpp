// Solve 2022-06-03
// Update 2023-03-13

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int ans;
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            ans = -1;
        }
        else {
            int dx = x1 - x2;
            int dy = y1 - y2;
            double d = sqrt(dx * dx + dy * dy);

            int min_d = abs(r1 - r2);
            int max_d = r1 + r2;

            if (d < min_d || d > max_d) {
                ans = 0;
            }
            else if (d == min_d || d == max_d) {
                ans = 1;
            }
            else {
                ans = 2;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

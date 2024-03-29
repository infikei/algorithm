// Solve 2023-09-25
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

    int n, x, y, r;
    cin >> n >> x >> y >> r;

    int xl = x - r;
    int xr = x + r;
    int cnt_a = 0;
    int cnt_b = 0;

    for (int i = 0; i < n; i++) {
        int nx;
        cin >> nx;

        if (xl < nx && nx < xr) cnt_a++;
        else if (nx == xl || nx == xr) cnt_b++;
    }

    cout << cnt_a << ' ' << cnt_b << '\n';

    return 0;
}

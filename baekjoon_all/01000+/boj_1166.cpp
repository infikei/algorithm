// Solve 2024-05-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l, w, h;
    cin >> n >> l >> w >> h;

    double low = 0.001;
    double high = 1000000001;

    int iter = 10000;

    while (iter-- > 0) {
        double mid = (low + high) * 0.5;
        ll mid_val = (ll) (l / mid) * (ll) (w / mid) * (ll) (h / mid);

        if (mid_val >= n) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    SETPRECISION(10);
    cout << low << '\n';

    return 0;
}

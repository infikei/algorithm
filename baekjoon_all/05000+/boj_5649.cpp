// Solve 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll sx = 0, sy = 0, sxx = 0, sxy = 0;

    for (int i = 0; i < n; i++) {
        ll xi, yi;
        cin >> xi >> yi;

        sx += xi;
        sy += yi;
        sxx += xi * xi;
        sxy += xi * yi;
    }

    double a = (double)(n * sxy - sx * sy) / (n * sxx - sx * sx);
    double b = (sy - a * sx) / n;

    SETPRECISION(3);

    cout << a << '\n';
    cout << b << '\n';

    return 0;
}

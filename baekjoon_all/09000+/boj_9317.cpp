// Solve 2023-12-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(2);

    while (true) {
        double d;
        int r_w, r_h;
        cin >> d >> r_w >> r_h;

        if (d == 0 && r_w == 0 && r_h == 0) break;

        double dpi_w = r_w * sqrt(337) / (16 * d);
        double dpi_h = r_h * sqrt(337) / (9 * d);

        cout << "Horizontal DPI: " << dpi_w << '\n';
        cout << "Vertical DPI: " << dpi_h << '\n';
    }

    return 0;
}

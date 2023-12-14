// Solve 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    const double PI = 3.14159;

    int n;
    cin >> n;

    double max_volume = 0.;

    for (int i = 0; i < n; i++) {
        char figure_type;
        cin >> figure_type;

        double volume;

        if (figure_type == 'C') {
            double r, h;
            cin >> r >> h;

            volume = r * r * h * PI / 3;
        }
        else if (figure_type == 'L') {
            double r, h;
            cin >> r >> h;

            volume = r * r * h * PI;
        }
        else {
            double r;
            cin >> r;

            volume = r * r * r * PI * 4 / 3;
        }

        if (volume > max_volume) {
            max_volume = volume;
        }
    }

    SETPRECISION(3);

    cout << max_volume << '\n';

    return 0;
}

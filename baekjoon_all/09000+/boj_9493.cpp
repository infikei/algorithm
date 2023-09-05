// Solve 2023-09-05

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
        ll m, a, b;
        cin >> m >> a >> b;
        if (m == 0) break;

        ll ans = round((double)(3600 * m * (b - a)) / (a * b));

        ll hh = ans / 3600;
        ll mm = ans / 60 % 60;
        ll ss = ans % 60;

        cout << hh << ':';

        if (mm < 10) cout << 0 << mm << ':';
        else cout << mm << ':';

        if (ss < 10) cout << 0 << ss << '\n';
        else cout << ss << '\n';
    }

    return 0;
}

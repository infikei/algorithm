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

    int t;
    cin >> t;

    int cnt = 0;

    for (int ti = 0; ti < t; ti++) {
        double z, x, y, w;
        cin >> z >> x >> y >> w;

        if (w > 7) {
            cout << 0 << '\n';
        }
        else if (z <= 56 && x <= 45 && y <= 25) {
            cout << 1 << '\n';
            cnt++;
        }
        else if ((z + x + y) <= 125) {
            cout << 1 << '\n';
            cnt++;
        }
        else {
            cout << 0 << '\n';
        }
    }

    cout << cnt << '\n';

    return 0;
}

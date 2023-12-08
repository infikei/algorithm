// Solve 2023-12-07

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
        int l, w, h, v;
        cin >> l >> w >> h >> v;

        if (l == 0 && w == 0) break;

        if (l == 0) {
            cout << v / w / h << ' ' << w << ' ' << h << ' ' << v << '\n';
        }
        else if (w == 0) {
            cout << l << ' ' << v / l / h << ' ' << h << ' ' << v << '\n';
        }
        else if (h == 0) {
            cout << l << ' ' << w << ' ' << v / l / w << ' ' << v << '\n';
        }
        else {
            cout << l << ' ' << w << ' ' << h << ' ' << l * w * h << '\n';
        }
    }

    return 0;
}

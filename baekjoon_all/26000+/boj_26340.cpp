// Solve 2023-09-29

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

    for (int ti = 0; ti < t; ti++) {
        if (ti >= 1) cout << '\n';

        int w, h, cnt;
        cin >> w >> h >> cnt;

        cout << "Data set: " << w << ' ' << h << ' ' << cnt << '\n';

        if (w < h) swap(w, h);

        while (--cnt >= 0) {
            w /= 2;

            if (w < h) swap(w, h);
        }

        cout << w << ' ' << h << '\n';
    }

    return 0;
}

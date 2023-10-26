// Solve 2023-10-25

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
        int rr = 0, gg = 0, bb = 0;

        for (int i = 0; i < 10; i++) {
            int r, g, b;
            cin >> r >> g >> b;

            rr += r; gg += g; bb += b;
        }

        rr = round(rr * 0.1);
        gg = round(gg * 0.1);
        bb = round(bb * 0.1);

        cout << rr << ' ' << gg << ' ' << bb << '\n';
    }

    return 0;
}

// Solve 2022-12-06
// Update 2024-01-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;

    int np = (p + t) % (w * 2);

    if (np > w) {
        np = w * 2 - np;
    }

    int nq = (q + t) % (h * 2);

    if (nq > h) {
        nq = h * 2 - nq;
    }

    cout << np << ' ' << nq << '\n';

    return 0;
}

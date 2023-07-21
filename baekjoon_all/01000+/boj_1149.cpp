// Solve 2022-06-03
// Update 2023-07-20

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

    int r, g, b, nr, ng, nb;
    cin >> r >> g >> b;

    for (int i = 1; i < n; i++) {
        cin >> nr >> ng >> nb;

        nr += min(g, b);
        ng += min(r, b);
        nb += min(r, g);

        r = nr;
        g = ng;
        b = nb;
    }

    cout << min(r, min(g, b)) << '\n';

    return 0;
}

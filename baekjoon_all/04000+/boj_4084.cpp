// Solve 2023-10-04

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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == 0) break;

        int iter = 0;

        while (a != b || b != c || c != d) {
            iter++;

            int na = abs(a - b);
            int nb = abs(b - c);
            int nc = abs(c - d);
            int nd = abs(d - a);

            a = na;
            b = nb;
            c = nc;
            d = nd;
        }

        cout << iter << '\n';
    }

    return 0;
}

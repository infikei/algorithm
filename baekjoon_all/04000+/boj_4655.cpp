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
        double d;
        cin >> d;

        if (d == 0) break;

        int i = 1;
        double val = 0;

        while (val < d) {
            val += 1.0 / ++i;
        }

        cout << --i << " card(s)\n";
    }

    return 0;
}

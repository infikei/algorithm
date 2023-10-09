// Solve 2023-01-02
// Update 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    cout << "n e\n";
    cout << "- -----------\n";

    double e = 0;
    int fac = 1;

    for (int i = 0; i < 10; i++) {
        if (i > 0) fac *= i;

        e += 1.0 / fac;

        if (i > 2) SETPRECISION(9);

        cout << i << ' ' << e << '\n';
    }

    return 0;
}

// Solve 2023-12-11

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
        double x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        double adam = x1 * y2 + y1 * z2 + z1 * x2;
        double gosia = x1 * z2 + y1 * x2 + z1 * y2;

        if (adam > gosia) cout << "ADAM\n";
        else if (adam < gosia) cout << "GOSIA\n";
        else cout << "=\n";
    }

    return 0;
}

// Solve 2023-09-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int d1, y1, d2, y2;
    cin >> d1 >> y1 >> d2 >> y2;

    d1 = -d1;
    d2 = -d2;

    if (d1 < 0) d1 += y1;
    if (d2 < 0) d2 += y2;

    for (int i = d1; i <= 5000; i += y1) {
        if (i % y2 == d2) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}

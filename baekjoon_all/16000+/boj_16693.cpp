// Solve 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const double PI = M_PI;

int main() {
    FASTIO;

    int a, p1, r, p2;
    cin >> a >> p1 >> r >> p2;

    if (a * p2 > r * r * p1 * PI) {
        cout << "Slice of pizza\n";
    }
    else {
        cout << "Whole pizza\n";
    }

    return 0;
}

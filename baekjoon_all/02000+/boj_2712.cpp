// Solve 2023-10-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(4);

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        double val;
        string unit;
        cin >> val >> unit;

        if (unit == "kg") {
            cout << val * 2.2046 << " lb\n";
        }
        else if (unit == "lb") {
            cout << val * 0.4536 << " kg\n";
        }
        else if (unit == "l") {
            cout << val * 0.2642 << " g\n";
        }
        else {
            cout << val * 3.7854 << " l\n";
        }
    }

    return 0;
}

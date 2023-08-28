// Solve 2023-08-28

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
        double x, y;
        cin >> x >> y;

        if (x == 0 && y == 0) {
            cout << "AXIS\n";
            break;
        }

        if (x == 0 || y == 0) {
            cout << "AXIS\n";
        }
        else if (x > 0) {
            if (y > 0) {
                cout << "Q1\n";
            }
            else {
                cout << "Q4\n";
            }
        }
        else {
            if (y > 0) {
                cout << "Q2\n";
            }
            else {
                cout << "Q3\n";
            }
        }
    }

    return 0;
}

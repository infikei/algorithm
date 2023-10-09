// Solve 2022-10-25
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

    SETPRECISION(3);

    int ti = 1;

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;

        if (ti >= 2) cout << '\n';

        cout << "Triangle #" << ti++ << '\n';

        if (a == -1) {
            if (b >= c) {
                cout << "Impossible.\n";
            }
            else {
                cout << "a = " << sqrt(c * c - b * b) << '\n';
            }
        }
        else if (b == -1) {
            if (a >= c) {
                cout << "Impossible.\n";
            }
            else {
                cout << "b = " << sqrt(c * c - a * a) << '\n';
            }
        }
        else {
            cout << "c = " << sqrt(a * a + b * b) << '\n';
        }
    }

    return 0;
}

// Solve 2023-09-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x, y, z, xx, yy, zz;
    cin >> x >> y >> z >> xx >> yy >> zz;

    if (yy == y) {
        if (xx == x) {
            cout << "A\n";
        }
        else if (xx >= (x + 1) / 2) {
            cout << "B\n";
        }
        else {
            cout << "C\n";
        }
    }
    else if (yy >= (y + 1) / 2) {
        cout << "D\n";
    }
    else {
        cout << "E\n";
    }

    return 0;
}

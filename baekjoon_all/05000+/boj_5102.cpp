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
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        a -= b;

        if (a % 2 == 0) {
            cout << a / 2 << ' ' << 0 << '\n';
        }
        else if (a == 1) {
            cout << 0 << ' ' << 0 << '\n';
        }
        else {
            cout << (a - 3) / 2 << ' ' << 1 << '\n';
        }
    }

    return 0;
}

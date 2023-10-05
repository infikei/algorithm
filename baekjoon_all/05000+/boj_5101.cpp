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
        int a1, d, an;
        cin >> a1 >> d >> an;

        if (a1 == 0 && d == 0 && an == 0) break;

        if ((an - a1) % d == 0 && (an - a1) / d >= 0) {
            cout << (an - a1) / d + 1 << '\n';
        }
        else {
            cout << "X\n";
        }
    }

    return 0;
}

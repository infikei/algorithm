// Solve 2023-07-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int aa, ad, ba, bd;
    cin >> aa >> ad >> ba >> bd;

    while (true) {
        ad -= ba;
        bd -= aa;

        if (ad <= 0) {
            if (bd <= 0) {
                cout << "DRAW\n";
                break;
            }
            cout << "PLAYER B\n";
            break;
        }
        if (bd <= 0) {
            cout << "PLAYER A\n";
            break;
        }
    }

    return 0;
}

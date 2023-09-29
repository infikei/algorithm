// Solve 2023-09-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int mod7 = 0, mod11 = 0;

    for (int i = 1; i <= n; i++) {
        if (++mod7 == 7) mod7 = 0;
        if (++mod11 == 11) mod11 = 0;

        if (mod7 == 0) {
            if (mod11 == 0) {
                cout << "Wiwat!\n";
            }
            else {
                cout << "Hurra!\n";
            }
        }
        else {
            if (mod11 == 0) {
                cout << "Super!\n";
            }
            else {
                cout << i << '\n';
            }
        }
    }

    return 0;
}

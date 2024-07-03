// Solve 2024-03-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 0 << '\n';
        }
        else {
            cout << 1;

            int iter = n - 2;

            while (iter-- > 0) {
                cout << 2;
            }

            cout << 1 << '\n';
        }
    }

    return 0;
}

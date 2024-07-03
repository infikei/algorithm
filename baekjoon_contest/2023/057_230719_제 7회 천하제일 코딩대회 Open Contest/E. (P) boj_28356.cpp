// Solve 2023-07-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        if (m == 1) {
            cout << 1 << '\n';
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';

            for (int col = 0; col < m; col++) {
                cout << (col & 1) + 1 << ' ';
            }
            cout << '\n';
        }
    }
    else if (m == 1) {
        cout << 2 << '\n';

        for (int row = 0; row < n; row++) {
            cout << (row & 1) + 1 << '\n';
        }
    }
    else {
        cout << 4 << '\n';

        for (int row = 0; row < n; row++) {
            int x = ((row & 1) << 1) + 1;
            for (int col = 0; col < m; col++) {
                cout << x + (col & 1) << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

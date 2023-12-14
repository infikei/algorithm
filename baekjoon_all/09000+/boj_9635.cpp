// Solve 2023-12-14

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

    for (int ti = 0; ti < t; ti++) {
        int n, x, y;
        cin >> n >> x >> y;

        int a0;
        cin >> a0;

        for (int i = 2; i < n; i++) {
            int a;
            cin >> a;
        }

        int al;
        cin >> al;

        if (a0 == x) {
            if (al == y) {
                cout << "BOTH\n";
            }
            else {
                cout << "EASY\n";
            }
        }
        else {
            if (al == y) {
                cout << "HARD\n";
            }
            else {
                cout << "OKAY\n";
            }
        }
    }

    return 0;
}

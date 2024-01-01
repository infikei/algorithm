// Solve 2023-12-30

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
        int n;
        cin >> n;

        int w_sum = 0;

        for (int i = 0; i < n; i++) {
            int w;
            cin >> w;
            w_sum += w;
        }

        if (w_sum > 0) {
            cout << "Right\n";
        }
        else if (w_sum < 0) {
            cout << "Left\n";
        }
        else {
            cout << "Equilibrium\n";
        }
    }

    return 0;
}

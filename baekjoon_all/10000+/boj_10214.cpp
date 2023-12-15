// Solve 2022-11-04
// Update 2023-12-15

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
        int y_sum = 0;
        int k_sum = 0;

        for (int i = 0; i < 9; i++) {
            int y, k;
            cin >> y >> k;

            y_sum += y;
            k_sum += k;
        }

        if (y_sum > k_sum) {
            cout << "Yonsei\n";
        }
        else if (y_sum < k_sum) {
            cout << "Korea\n";
        }
        else {
            cout << "Draw\n";
        }
    }

    return 0;
}

// Solve 2022-06-08
// Update 2024-01-31

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

    int two_power_n = (1 << n);

    for (int i = 0; i < two_power_n; i++) {
        int cnt = 0;

        for (int bit = 1; bit != two_power_n; bit <<= 1) {
            if ((i & bit) == 0) {
                cnt++;
            }
        }

        if (cnt == m) {
            for (int j = 1, bit = (two_power_n >> 1); bit != 0; j++, bit >>= 1) {
                if ((i & bit) == 0) {
                    cout << j << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}

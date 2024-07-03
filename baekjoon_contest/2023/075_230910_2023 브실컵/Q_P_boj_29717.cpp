// Solve 2023-09-10
// Update 2023-12-26

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
        ll n;
        cin >> n;

        ll n_val = n * (n + 1) >> 1;
        ll low = -1;
        ll high = 3e9;

        while (low + 1 < high) {
            ll mid = (low + high) >> 1;
            ll mid_val = mid * (mid + 1);

            if (mid_val > n_val) high = mid;
            else low = mid;
        }

        cout << high << '\n';
    }

    return 0;
}

// Solve 2023-06-25

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

        ll low = 0, high = 1e8;
        while (low + 1 < high) {
            ll mid = (low + high) >> 1;
            ll val = (mid * (mid * 3 + 1)) >> 1;

            if (val >= n) {
                high = mid;
            }
            else {
                low = mid;
            }
        }

        ll a = high;
        ll k = ((a - 1) * (a * 3 - 2)) >> 1;

        if (n <= k + a) {
            ll row = a * 3 - 2;
            ll col = n - k;
            cout << (((row - 1) * row) >> 1) + 1 + (col - 1) * 3 << '\n';
        }
        else if (n <= k + (a << 1) - 1) {
            ll row = a * 3 - 1;
            ll col = n - k - a;
            cout << (((row - 1) * row) >> 1) + 3 + (col - 1) * 3 << '\n';
        }
        else {
            ll row = a * 3;
            ll col = n - k - (a << 1) + 1;
            cout << (((row - 1) * row) >> 1) + 2 + (col - 1) * 3 << '\n';
        }
    }

    return 0;
}

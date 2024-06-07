// Solve 2022-11-08
// Update 2024-06-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;

int main() {
    FASTIO;

    uint s;
    cin >> s;

    uint low = 1;
    uint high = 92682;

    while (low + 1 < high) {
        uint mid = (low + high) >> 1;
        uint val;

        if (mid & 1) {
            val = (mid + 1) / 2 * mid;
        }
        else {
            val = mid / 2 * (mid + 1);
        }

        if (s >= val) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}

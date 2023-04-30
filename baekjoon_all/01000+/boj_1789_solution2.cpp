// Solve 2022-11-08
// Update 2023-04-30

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    uint s;
    cin >> s;

    uint left = 1, right = 92682;
    while (left + 1 < right) {
        uint mid = (left + right) >> 1;
        uint val;
        if (mid & 1) {
            val = (mid + 1) / 2 * mid;
        }
        else {
            val = mid / 2 * (mid + 1);
        }

        if (s >= val) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left << '\n';

    return 0;
}

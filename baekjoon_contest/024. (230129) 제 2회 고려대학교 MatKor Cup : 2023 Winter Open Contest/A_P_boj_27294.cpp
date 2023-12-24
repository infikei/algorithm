// Solve 2023-01-29
// Update 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t, s;
    cin >> t >> s;

    if (s == 0 && t >= 12 && t <= 16) {
        cout << 320 << '\n';
    }
    else {
        cout << 280 << '\n';
    }

    return 0;
}

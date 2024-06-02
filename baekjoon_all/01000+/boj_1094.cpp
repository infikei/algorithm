// Solve 2022-07-30
// Update 2024-06-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x;
    cin >> x;

    int ans = 0;

    while (x != 0) {
        if (x & 1) ans++;

        x >>= 1;
    }

    cout << ans << '\n';

    return 0;
}

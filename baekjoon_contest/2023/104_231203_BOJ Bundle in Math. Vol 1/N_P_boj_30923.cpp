// Solve 2023-12-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll ans = n * 2;
    int h0 = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        ans += h * 2 + abs(h - h0);
        h0 = h;
    }

    ans += h0;

    cout << ans << '\n';

    return 0;
}

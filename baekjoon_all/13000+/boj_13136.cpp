// Solve 2022-11-02
// Update 2023-11-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll r, c, n;
    cin >> r >> c >> n;

    ll ans = ((r - 1) / n + 1) * ((c - 1) / n + 1);

    cout << ans << '\n';

    return 0;
}

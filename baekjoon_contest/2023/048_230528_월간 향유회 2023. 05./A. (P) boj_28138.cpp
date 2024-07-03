// Solve 2023-05-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n, r;
    cin >> n >> r;

    ll nr = n - r;
    ll ans = 0;

    for (ll i = 1; ; i++) {
        ll j = nr / i;
        if (i > j) break;
        if (nr % i != 0) continue;

        if (i > r) ans += i;

        if (i == j) break;
        if (j > r) ans += j;
    }

    cout << ans << '\n';

    return 0;
}

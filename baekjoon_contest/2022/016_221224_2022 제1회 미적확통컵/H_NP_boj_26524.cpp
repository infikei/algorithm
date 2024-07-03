// Solve 2023-07-31
// Update 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    ll ans = 1;

    for (ll i = 2; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}

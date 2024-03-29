// Solve 2023-04-27
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll f(ll n) {
    if (n == 0) return 0;

    ll res = 0;
    ll k = 1;
    ll k2 = 2;

    while (true) {
        res += k * ((n - k + 1) / k2) + min(k, (n - k + 1) % k2);
        k = k2;
        k2 <<= 1;

        if (n < k) break;
    }

    return res;
}

int main() {
    FASTIO;

    ll a, b;
    cin >> a >> b;

    ll ans = f(b) - f(a - 1);

    cout << ans << '\n';

    return 0;
}

// Solve 2023-09-21

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

    int p, k;
    ll c;
    cin >> p >> c >> k;

    vector<ll> m(p);

    for (ll &x : m) {
        cin >> x;
    }

    vector<ll> d(p);

    for (int i = 1; i < p; i++) {
        d[i] = m[i] - m[i - 1];
    }

    ll dp = 0, cp = c;

    for (int i = 1; i < p; i++) {
        dp += -cp * d[p - i];

        if (dp >= 0) {
            dp %= MOD;
        }
        else {
            dp = -(-dp % MOD);
        }

        cp *= c;
        cp %= MOD;
    }

    d.push_back(dp);

    ll ans = abs(d[(k - 1) % p + 1]);
    int iter = (k - 1) / p;

    while (--iter >= 0) {
        ans *= cp;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}

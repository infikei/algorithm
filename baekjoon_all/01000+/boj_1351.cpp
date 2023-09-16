// Solve 2023-09-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll p, q;
unordered_map<ll, ll> dp;

ll f(ll n) {
    if (dp.find(n) != dp.end()) return dp[n];

    return dp[n] = f(n / p) + f(n / q);
}

int main() {
    FASTIO;

    dp[0] = 1;

    ll n;
    cin >> n >> p >> q;

    cout << f(n) << '\n';

    return 0;
}

// Solve 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    ll n_fac = 1;
    ll a_fac = 1;
    ll b_fac = 1;
    ll c_fac = 1;

    for (int i = 2; i <= n; i++) {
        n_fac *= i;
    }

    for (int i = 2; i <= a; i++) {
        a_fac *= i;
    }

    for (int i = 2; i <= b; i++) {
        b_fac *= i;
    }

    for (int i = 2; i <= c; i++) {
        c_fac *= i;
    }

    ll ans = n_fac / a_fac / b_fac / c_fac;
    cout << ans << '\n';

    return 0;
}

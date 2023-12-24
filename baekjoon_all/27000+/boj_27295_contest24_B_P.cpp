// Solve 2023-01-29
// Update 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll n, b, xs, ys;

ll calc_gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    return calc_gcd(b, a % b);
}

void solve() {
    if (xs == 0) {
        cout << "EZPZ\n";
        return;
    }

    ll p = ys - b * n;
    ll q = xs;

    if (p % q == 0) {
        cout << p / q << '\n';
        return;
    }

    if (q < 0) {
        p = -p;
        q = -q;
    }

    ll gcd_p_q = calc_gcd(abs(p), q);
    p /= gcd_p_q;
    q /= gcd_p_q;

    cout << p << '/' << q << '\n';
}

int main() {
    FASTIO;

    cin >> n >> b;

    for (ll i = 0; i < n; i++) {
        ll xi, yi;
        cin >> xi >> yi;

        xs += xi;
        ys += yi;
    }

    solve();

    return 0;
}

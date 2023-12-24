// Solve 2023-01-29
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll calc_gcd(ll a, ll b) {
    ll r = a % b;

    if (r == 0) return b;

    return calc_gcd(b, r);
}

int main() {
    FASTIO;

    ll n, b;
    cin >> n >> b;

    ll x_sum = 0;
    ll y_sum = 0;

    for (ll i = 0; i < n; i++) {
        ll xi, yi;
        cin >> xi >> yi;

        x_sum += xi;
        y_sum += yi;
    }

    if (x_sum == 0) {
        cout << "EZPZ\n";
    }
    else {
        ll p = y_sum - b * n;
        ll q = x_sum;

        if (p % q == 0) {
            cout << p / q << '\n';
        }
        else {
            if (q < 0) {
                p = -p;
                q = -q;
            }

            ll gcd_p_q = calc_gcd(abs(p), q);
            p /= gcd_p_q;
            q /= gcd_p_q;

            cout << p << '/' << q << '\n';
        }
    }

    return 0;
}

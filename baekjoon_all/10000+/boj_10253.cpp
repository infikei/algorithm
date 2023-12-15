// Solve 2022-08-03
// Update 2023-12-15

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

void calc(ll &a, ll &b) {
    ll x = b / a + 1;
    ll gcd = calc_gcd(x, b);
    a = (a * x - b) / gcd;
    b = b / gcd * x;

    gcd = calc_gcd(b, a);
    a /= gcd;
    b /= gcd;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        ll a, b;
        cin >> a >> b;

        while (a != 1) {
            calc(a, b);
        }

        cout << b << '\n';
    }

    return 0;
}

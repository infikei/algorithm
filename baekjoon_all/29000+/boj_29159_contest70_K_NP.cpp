// Solve 2023-09-04

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

void print_irreducible_fraction(ll n, ll m) {
    if (m < 0) {
        n = -n;
        m = -m;
    }

    if (n > 0) {
        ll gcd = calc_gcd(n, m);
        n /= gcd;
        m /= gcd;
    }
    else if (n < 0) {
        ll gcd = calc_gcd(-n, m);
        n /= gcd;
        m /= gcd;
    }
    else {
        m = 1;
    }

    if (m == 1) {
        cout << n;
    }
    else {
        cout << n << '/' << m;
    }
}

int main() {
    FASTIO;

    ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    for (int i = 0; i < 4; i++) {
        ll x, y;
        cin >> x >> y;

        x1 += x; y1 += y;
    }

    for (int i = 0; i < 4; i++) {
        ll x, y;
        cin >> x >> y;

        x2 += x; y2 += y;
    }

    ll a2 = y1 - y2; // a의 분자
    ll a1 = x1 - x2; // a의 분모
    ll b2 = x1 * y2 - x2 * y1; // b의 분자
    ll b1 = 4 * a1; // b의 분모

    print_irreducible_fraction(a2, a1);
    cout << ' ';
    print_irreducible_fraction(b2, b1);
    cout << '\n';

    return 0;
}

#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll n, b, x, y;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

void solve() {
    if (x == 0) {
        cout << "EZPZ\n";
        return;
    }

    ll p = y - b * n;
    ll q = x;
    if (p % q == 0) {
        cout << p / q << '\n';
        return;
    }

    if (q < 0) {
        p = -p;
        q = -q;
    }

    ll gcdpq = gcd(abs(p), q);
    p /= gcdpq;
    q /= gcdpq;
    cout << p << '/' << q << '\n';
}

int main() {
    fastio;

    cin >> n >> b;
    for (ll i = 0; i < n; i++) {
        ll xi, yi;
        cin >> xi >> yi;
        x += xi;
        y += yi;
    }

    solve();

    return 0;
}
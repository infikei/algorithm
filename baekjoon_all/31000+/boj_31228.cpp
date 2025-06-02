// Solve 2025-05-31

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ll get_gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FASTIO;

    ll n, k;
    cin >> n >> k;

    ll gcd = get_gcd(n, k);
    n /= gcd;
    k /= gcd;

    if (k > n - k) {
        k = n - k;
    }

    ll ans = n * (k - 1);

    cout << ans << '\n';

    return 0;
}

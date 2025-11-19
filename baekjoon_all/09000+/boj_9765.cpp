// Solve 2025-11-19

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

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

    ll c[7];

    for (int i = 1; i <= 6; i++) {
        cin >> c[i];
    }

    ll x[8] = {0};

    x[2] = get_gcd(c[1], c[5]);
    x[1] = c[1] / x[2];
    x[3] = c[5] / x[2];

    x[6] = get_gcd(c[6], c[3]);
    x[5] = c[6] / x[6];
    x[7] = c[3] / x[6];

    cout << x[1] << ' ' << x[2] << ' ' << x[3] << ' ';
    cout << x[5] << ' ' << x[6] << ' ' << x[7] << '\n';
    return 0;
}

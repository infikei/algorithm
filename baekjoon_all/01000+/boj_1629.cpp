// Solve 2022-12-06
// Update 2025-02-21

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

ll calc_pow(ll a, ll b, ll mod) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    FASTIO;

    ll a, b, c;
    cin >> a >> b >> c;

    cout << calc_pow(a, b, c) << '\n';

    return 0;
}

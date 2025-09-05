// Solve 2025-08-30

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
        ll tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

ll get_lcm(ll a, ll b) {
    return a / get_gcd(a, b) * b;
}

ll solution(ll n, ll a, ll b, ll c) {
    ll abbcca = a * b + b * c + c * a;
    ll abc = a * b * c;
    ll nabc = n * abc;

    if (nabc % abbcca != 0) {
        return -1;
    }

    ll k = nabc / abbcca - n;

    if (k < 0) {
        return -1;
    }

    ll lcm = get_lcm(a, get_lcm(b, c));

    if ((n + k) % lcm != 0) {
        return -1;
    }

    return k;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << solution(n, a, b, c) << '\n';
    }

    return 0;
}

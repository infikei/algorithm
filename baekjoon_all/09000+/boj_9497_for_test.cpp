// Solve 2025-09-12

// 유사 문제 : 5025, 9497, 13435

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
    while (b > 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ll f(ll n, ll m) {
    if (n == 1) return m;
    if (m == 1) return n;

    ll gcd = get_gcd(n - 1, m - 1);

    if (gcd == 1) {
        return n * m / 2;
    }

    ll nn = n / gcd + 1;
    ll mm = m / gcd + 1;
    return f(nn, mm) + (n - nn) * (m / gcd);
}

ll f_bruteforce(ll n, ll m) {
    if (n == 1) return m;
    if (m == 1) return n;

    unordered_set<ll> hs;
    ll i = 1;
    ll di = 1;
    ll j = 1;
    ll dj = 1;
    hs.insert((i << 10) + j);

    while (true) {
        i += di;
        j += dj;
        hs.insert((i << 10) + j);

        if (i == 1 && j == 1) break;

        if (i == n) {
            di = -1;
        }
        else if (i == 1) {
            di = 1;
        }

        if (j == m) {
            dj = -1;
        }
        else if (j == 1) {
            dj = 1;
        }
    }

    return size(hs);
}

int main() {
    FASTIO;

    ll n, m;
    cin >> n >> m;
    ll ans = f(n, m);
    ll ans2 = f_bruteforce(n, m);
    cout << ans << '\n';

    if (ans != ans2) {
        cout << ans2 << '\n';
    }

    return 0;
}

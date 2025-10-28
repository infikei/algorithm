// Solve 2025-10-27

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

ll f(ll n, ll k) {
    if (n == 1) return 0;
    if (k == 1) return n - 1;

    if (n < k) {
        ll val = 0;

        for (int i = 2; i <= n; i++) {
            val = (val + k) % i;
        }

        return val;
    }

    ll q = n / k;
    ll r = n % k;
    ll y = f(n - q, k);

    if (y < r) {
        ll n2 = q * k;
        return (y + n2) % n;
    }
    else {
        ll q2 = (y - r) / (k - 1);
        ll r2 = (y - r) % (k - 1);
        return q2 * k + r2;
    }
}

int main() {
    FASTIO;

    ll n, k;
    cin >> n >> k;

    cout << f(n, k) + 1 << '\n';
    return 0;
}

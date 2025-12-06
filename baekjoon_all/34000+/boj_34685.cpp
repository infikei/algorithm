// Solve 2025-12-05

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

int main() {
    FASTIO;

    ll k;
    cin >> k;

    ll abs_k = abs(k);
    ll kk = k * (ll) k;
    set<ll> st;

    for (ll i = 1; i <= abs_k; i++) {
        if (kk % i != 0) continue;

        ll j = kk / i;
        st.insert(k * 2 - i - j);
        st.insert(k * 2 + i + j);
    }

    ll s = 0;

    for (ll p : st) {
        s += p;
    }

    cout << size(st) << ' ' << s << '\n';
    return 0;
}

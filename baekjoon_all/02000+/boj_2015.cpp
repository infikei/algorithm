// Solve 2025-06-23

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

    int n;
    ll k;
    cin >> n >> k;

    ll ans = 0;
    ll prefix_sum = 0;
    unordered_map<ll, ll> hs;
    hs[0]++;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        prefix_sum += x;
        ans += hs[prefix_sum - k];
        hs[prefix_sum]++;
    }

    cout << ans << '\n';
    return 0;
}

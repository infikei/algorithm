// Solve 2025-06-23
// Update 2025-10-03

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

    ll cnt = 0;
    ll prefix_sum = 0;
    map<ll, int> mp;
    mp[0]++;

    for (int i = 0; i < n; i++) {
        ll v;
        cin >> v;
        prefix_sum += v;
        cnt += mp[prefix_sum - k];
        mp[prefix_sum]++;
    }

    cout << cnt << '\n';
    return 0;
}

// Solve 2026-09-06

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
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;

ll prefix_min_a[200000];
ll prefix_sum_diff[200000];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<pll> v;
        ll b_sum = 0;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a - b, b});
            b_sum += b;
        }

        sort(v.begin(), v.end());
        prefix_min_a[0] = v[0].first + v[0].second;
        prefix_sum_diff[0] = v[0].first;

        for (int i = 1; i < n; i++) {
            prefix_min_a[i] = min(prefix_min_a[i - 1], v[i].first + v[i].second);
            prefix_sum_diff[i] = prefix_sum_diff[i - 1] + v[i].first;
        }

        ll mn = LLINF;

        for (int i = 0; i < n; i++) {
            ll cur = b_sum + prefix_sum_diff[i] + max(0, n - (i + 1) * 2) * prefix_min_a[i];
            mn = min(mn, cur);
        }

        cout << mn << '\n';
    }

    return 0;
}

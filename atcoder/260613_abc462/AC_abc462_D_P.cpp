// Solve 2026-06-13

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

    int n, d;
    cin >> n >> d;

    vector<pii> v;

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;

        if (s + d <= t) {
            v.emplace_back(s + d, 1);
            v.emplace_back(t + 1, -1);
        }
    }

    sort(v.begin(), v.end());
    int idx = 0;
    ll ans = 0;
    int cur = 0;

    for (int i = 1; i <= 1000000; i++) {
        while (idx < size(v) && v[idx].first == i) {
            cur += v[idx].second;
            idx++;
        }

        ans += (ll) cur * (cur - 1) / 2;
    }

    cout << ans << '\n';
    return 0;
}

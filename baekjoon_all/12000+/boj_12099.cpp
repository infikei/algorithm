// Solve 2026-01-19

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

    int n, q;
    cin >> n >> q;
    vector<pii> vec;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.emplace_back(a, b);
    }

    sort(vec.begin(), vec.end());

    while (q-- > 0) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        auto it = lower_bound(vec.begin(), vec.end(), pii(u, 0));
        auto it_end = lower_bound(vec.begin(), vec.end(), pii(v + 1, 0));
        int cnt = 0;

        while (it != it_end) {
            if (x <= it->second && it->second <= y) {
                cnt++;
            }

            it++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

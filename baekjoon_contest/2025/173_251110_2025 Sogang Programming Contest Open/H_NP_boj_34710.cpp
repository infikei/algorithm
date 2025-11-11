// Solve 2025-11-10

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
    cin >> n;
    vector<pii> vec;

    for (int i = 0; i < n; i++) {
        int t, l;
        cin >> t >> l;
        vec.emplace_back(t, l);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        if (vec[i].first < vec[i].second) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        int diff = vec[i].first - vec[i].second;
        int diff2 = vec[i + 1].first - vec[i + 1].second;

        if (diff > diff2) {
            vec[i].second = vec[i].first - diff2;
        }
    }

    int cur = 0;
    int k = 0, h = 0;
    ll s = 0;

    for (auto [t, l] : vec) {
        int dk = max(0, l - k);
        int dh = (t - cur) - dk;
        cur = t;
        k += dk;
        h += dh;
        s += h;
    }

    cout << s << '\n';
    return 0;
}

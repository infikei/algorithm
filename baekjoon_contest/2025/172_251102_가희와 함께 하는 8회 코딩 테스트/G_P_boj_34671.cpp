// Solve 2025-11-02

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

    int n, m, q;
    cin >> n >> m >> q;

    unordered_map<ll, int> edges;

    while (m-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) swap(a, b);

        ll idx = a * 1000000LL + b;

        if (edges.find(idx) == edges.end()) {
            edges[idx] = c;
        }
        else {
            edges[idx] = min(edges[idx], c);
        }
    }

    while (q-- > 0) {
        int s, e;
        cin >> s >> e;

        if (s > e) swap(s, e);

        ll idx = s * 1000000LL + e;

        if (edges.find(idx) == edges.end()) {
            cout << -1 << '\n';
        }
        else {
            cout << edges[idx] << '\n';
        }
    }

    return 0;
}

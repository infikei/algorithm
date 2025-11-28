// Solve 2025-11-28

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

int a[200001];
int b[200001];
ll f[200001];
vector<pii> adj[200001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++) {
        cin >> a[u];
    }

    for (int u = 1; u <= n; u++) {
        cin >> b[u];
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    memset(f, 0x3f, sizeof f);

    for (int u = 1; u <= n; u++) {
        if (u - a[u] < 1 || u + a[u] > n) {
            f[u] = b[u];
            pq.emplace(f[u], u);
            continue;
        }

        adj[u - a[u]].emplace_back(u, b[u]);
        adj[u + a[u]].emplace_back(u, b[u]);
    }

    while (!pq.empty()) {
        auto [cur_f, cur] = pq.top();
        pq.pop();

        if (cur_f > f[cur]) continue;

        for (auto [nxt, nxt_b] : adj[cur]) {
            ll nxt_f = cur_f + nxt_b;

            if (nxt_f < f[nxt]) {
                f[nxt] = nxt_f;
                pq.emplace(nxt_f, nxt);
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << f[u] << ' ';
    }

    cout << '\n';
    return 0;
}

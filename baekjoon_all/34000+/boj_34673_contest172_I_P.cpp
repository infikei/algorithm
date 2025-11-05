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

vector<pii> adj[400001];
int people[400001];
ll dist[400001];
map<ll, int> mp;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        adj[s].emplace_back(e, d);
        adj[e].emplace_back(s, d);
    }

    for (int u = 1; u <= n; u++) {
        cin >> people[u];
    }

    queue<int> que;
    memset(dist, -1, sizeof dist);
    que.push(1);
    dist[1] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (pii& nxt : adj[cur]) {
            if (dist[nxt.first] != -1) continue;

            dist[nxt.first] = dist[cur] + nxt.second;
            que.push(nxt.first);
        }
    }

    for (int u = 1; u <= n; u++) {
        ll key = dist[u] * 1000000001LL - people[u];
        mp[key]++;
    }

    ll ans = n * (ll) (n - 1) / 2;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans -= it->second * (ll) (it->second - 1) / 2;
    }

    cout << ans << ' ' << ans << '\n';
    return 0;
}

// Solve 2026-07-01

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

struct AdjNode{
    int to;
    ll dist;

    AdjNode(int to, ll dist) : to(to), dist(dist) {
    }

    bool operator>(const AdjNode& rhs) const {
        return dist > rhs.dist;
    }
};

vector<AdjNode> adj[100001];
ll min_dist[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    memset(min_dist, 0x3f, sizeof(min_dist));
    min_dist[1] = 0;
    priority_queue<AdjNode, vector<AdjNode>, greater<AdjNode>> pq;
    pq.emplace(1, 0);

    while (!pq.empty()) {
        auto [cur, cur_dist] = pq.top();
        pq.pop();

        if (cur_dist > min_dist[cur]) continue;

        for (auto [nxt, d] : adj[cur]) {
            ll nxt_dist = cur_dist + d;

            if (nxt_dist < min_dist[nxt]) {
                min_dist[nxt] = nxt_dist;
                pq.emplace(nxt, nxt_dist);
            }
        }
    }

    cout << min_dist[n] << '\n';
    return 0;
}

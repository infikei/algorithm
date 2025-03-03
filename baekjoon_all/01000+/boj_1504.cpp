// Solve 2023-01-06
// Update 2025-03-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e8;

int main() {
    FASTIO;

    int n, e;
    cin >> n >> e;

    vector<vector<pii>> edges(n + 1, vector<pii>());

    for (int i = 0; i < e; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;

        edges[from].emplace_back(to, dist);
        edges[to].emplace_back(from, dist);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dists(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    dists[v1] = 0;
    pq_mintop.emplace(0, v1);

    while (!pq_mintop.empty()) {
        int cur = pq_mintop.top().second;
        int dist_to_cur = pq_mintop.top().first;
        pq_mintop.pop();

        if (dists[cur] < dist_to_cur) continue;

        for (pii &edge : edges[cur]) {
            int nxt = edge.first;
            int dist_to_nxt = dist_to_cur + edge.second;

            if (dists[nxt] > dist_to_nxt) {
                dists[nxt] = dist_to_nxt;
                pq_mintop.emplace(dist_to_nxt, nxt);
            }
        }
    }

    int route1 = dists[1] + dists[v2];
    int route2 = dists[v2] + dists[n];

    dists.assign(n + 1, INF);
    dists[v2] = 0;
    pq_mintop.emplace(0, v2);

    while (!pq_mintop.empty()) {
        int cur = pq_mintop.top().second;
        int dist_to_cur = pq_mintop.top().first;
        pq_mintop.pop();

        if (dists[cur] < dist_to_cur) continue;

        for (pii &edge : edges[cur]) {
            int next = edge.first;
            int dist_to_next = dist_to_cur + edge.second;

            if (dists[next] > dist_to_next) {
                dists[next] = dist_to_next;
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    route1 += dists[n];
    route2 += dists[1];

    int ans = min(route1, route2);

    if (ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}

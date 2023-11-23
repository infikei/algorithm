// Solve 2023-01-06
// Update 2023-11-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e8;

int main() {
    FASTIO;

    int n, e;
    cin >> n >> e;

    vector<vector<pii> > edges(n + 1, vector<pii>());

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
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        if (dists[now] < dist_to_now) continue;

        for (pii edge : edges[now]) {
            int next = edge.first;
            int dist_to_next = dist_to_now + edge.second;

            if (dists[next] > dist_to_next) {
                dists[next] = dist_to_next;
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    int route1 = dists[1] + dists[v2];
    int route2 = dists[v2] + dists[n];

    dists.assign(n + 1, INF);
    dists[v2] = 0;
    pq_mintop.emplace(0, v2);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        if (dists[now] < dist_to_now) continue;

        for (pii edge : edges[now]) {
            int next = edge.first;
            int dist_to_next = dist_to_now + edge.second;

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

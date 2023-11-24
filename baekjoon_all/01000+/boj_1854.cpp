// Solve 2023-01-25
// Update 2023-11-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii> > edges(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;

        edges[from].emplace_back(to, dist);
    }

    vector<priority_queue<int> > dists(n + 1, priority_queue<int>());
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    dists[1].push(0);
    pq_mintop.emplace(0, 1);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        for (pii edge : edges[now]) {
            int next = edge.first;
            int dist_to_next = dist_to_now + edge.second;

            if (SIZE(dists[next]) < k) {
                dists[next].push(dist_to_next);
                pq_mintop.emplace(dist_to_next, next);
            }
            else if (dists[next].top() > dist_to_next) {
                dists[next].pop();
                dists[next].push(dist_to_next);
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        if (SIZE(dists[u]) < k) cout << -1 << '\n';
        else cout << dists[u].top() << '\n';
    }

    return 0;
}

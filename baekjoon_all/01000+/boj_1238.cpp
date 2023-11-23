// Solve 2023-01-23
// Update 2023-11-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int main() {
    FASTIO;

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pii> > roads(n + 1, vector<pii>());
    vector<vector<pii> > reversed_roads(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;

        roads[from].emplace_back(to, dist);
        reversed_roads[to].emplace_back(from, dist);
    }

    vector<int> dists(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    dists[x] = 0;
    pq_mintop.emplace(0, x);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        if (dists[now] < dist_to_now) continue;

        for (pii road : roads[now]) {
            int next = road.first;
            int dist_to_next = dist_to_now + road.second;

            if (dists[next] > dist_to_next) {
                dists[next] = dist_to_next;
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    vector<int> reversed_dists(n + 1, INF);
    reversed_dists[x] = 0;
    pq_mintop.emplace(0, x);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int reversed_dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        if (reversed_dists[now] < reversed_dist_to_now) continue;

        for (pii reversed_road : reversed_roads[now]) {
            int next = reversed_road.first;
            int reversed_dist_to_next = reversed_dist_to_now + reversed_road.second;

            if (reversed_dists[next] > reversed_dist_to_next) {
                reversed_dists[next] = reversed_dist_to_next;
                pq_mintop.emplace(reversed_dist_to_next, next);
            }
        }
    }

    int max_sum_dist = 0;

    for (int u = 1; u <= n; u++) {
        max_sum_dist = max(max_sum_dist, dists[u] + reversed_dists[u]);
    }

    cout << max_sum_dist << '\n';

    return 0;
}

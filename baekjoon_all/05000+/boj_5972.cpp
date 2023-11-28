// Solve 2023-11-28

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

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> edges(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;

        edges[from].emplace_back(to, dist);
        edges[to].emplace_back(from, dist);
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq_mintop;
    dist[1] = 0;
    pq_mintop.emplace(0, 1);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int dist_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        if (now == n) break;
        if (dist[now] < dist_to_now) continue;

        for (pii edge : edges[now]) {
            int next = edge.first;
            int dist_to_next = dist_to_now + edge.second;

            if (dist[next] > dist_to_next) {
                dist[next] = dist_to_next;
                pq_mintop.emplace(dist_to_next, next);
            }
        }
    }

    cout << dist[n] << '\n';

    return 0;
}

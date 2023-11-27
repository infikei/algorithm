// Solve 2023-01-24
// Update 2023-11-27

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

    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        int s, d;
        cin >> s >> d;

        vector<vector<pii>> edges(n, vector<pii>());

        for (int i = 0; i < m; i++) {
            int from, to, dist;
            cin >> from >> to >> dist;

            edges[from].emplace_back(to, dist);
        }

        // 1번째 다익스트라

        vector<int> dist(n, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq_mintop;
        vector<vector<int>> parents(n, vector<int>());
        dist[s] = 0;
        pq_mintop.emplace(0, s);

        while (!pq_mintop.empty()) {
            int now = pq_mintop.top().second;
            int dist_to_now = pq_mintop.top().first;
            pq_mintop.pop();

            if (now == d) break;
            if (dist[now] < dist_to_now) continue;

            for (pii edge : edges[now]) {
                int next = edge.first;
                int dist_to_next = dist_to_now + edge.second;

                if (dist[next] > dist_to_next) {
                    dist[next] = dist_to_next;
                    pq_mintop.emplace(dist_to_next, next);
                    parents[next].clear();
                    parents[next].push_back(now);
                }
                else if (dist[next] == dist_to_next) {
                    parents[next].push_back(now);
                }
            }
        }

        // 간선 제거

        queue<int> bfs_que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bfs_que.push(d);

        while (!bfs_que.empty()) {
            int now = bfs_que.front();
            bfs_que.pop();

            for (int parent : parents[now]) {
                if (visited[parent][now]) continue;

                visited[parent][now] = true;
                bfs_que.push(parent);

                for (pii &edge : edges[parent]) {
                    if (edge.first == now) {
                        edge.second = INF;
                        break;
                    }
                }
            }
        }

        // 2번째 다익스트라

        dist.assign(n, INF);
        pq_mintop = priority_queue<pii, vector<pii>, greater<pii>>();
        dist[s] = 0;
        pq_mintop.emplace(0, s);

        while (!pq_mintop.empty()) {
            int now = pq_mintop.top().second;
            int dist_to_now = pq_mintop.top().first;
            pq_mintop.pop();

            if (now == d) break;
            if (dist[now] < dist_to_now) continue;

            for (pii edge : edges[now]) {
                if (edge.second == INF) continue;

                int next = edge.first;
                int dist_to_next = dist_to_now + edge.second;

                if (dist[next] > dist_to_next) {
                    dist[next] = dist_to_next;
                    pq_mintop.emplace(dist_to_next, next);
                }
            }
        }

        // 결과 출력

        if (dist[d] == INF) cout << -1 << '\n';
        else cout << dist[d] << '\n';
    }

    return 0;
}

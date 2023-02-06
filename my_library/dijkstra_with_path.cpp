#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int vertex, edge, start;
vector<vector<pii> > edges;
vector<int> costs;
vector<vector<int> > parents;

void dijkstra(bool flag_parents = false) {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    costs.assign(vertex, INF);
    costs[start] = 0;
    pq_mintop.push({0, start});
    if (flag_parents) parents.assign(vertex, vector<int>());

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();
        if (now_cost > costs[now]) continue;

        for (auto edge : edges[now]) {
            int next = edge.first;
            int next_cost = now_cost + edge.second;
            if (costs[next] > next_cost) {
                costs[next] = next_cost;
                pq_mintop.push({next_cost, next});
                if (flag_parents) {
                    parents[next].clear();
                    parents[next].push_back(now);
                }
            }
            else if (flag_parents && costs[next] == next_cost) {
                parents[next].push_back(now);
            }
        }
    }
}

int main() {
    cin >> vertex >> edge >> start;

    edges.assign(vertex, vector<pii>());
    for (int i = 0; i < edge; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c}); // 양방향일 경우
    }

    dijkstra(true);

    return 0;
}
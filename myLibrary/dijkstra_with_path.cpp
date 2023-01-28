#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321; // 또는 1e9로 설정
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
    fastio;

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
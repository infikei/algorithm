#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321; // 또는 1e9로 설정
int vertex, edge, start, finish;
vector<vector<pii> > edges;
vector<int> costs;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    costs.assign(vertex, INF);
    costs[start] = 0;
    pq_mintop.push({0, start});

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();
        if (now == finish) break; // finish까지의 값만 구하는 경우라면 이 이후의 실행은 의미가 없으므로 finish에서 반복을 끝내서 시간을 단축한다.
        // 이렇게 하면 finish 점을 제외한 다른 점들에 대해서는 최단 거리 값이 아닐 수 있다. (중간에 실행을 멈췄으므로)
        if (now_cost > costs[now]) continue;

        for (auto edge : edges[now]) {
            int next = edge.first;
            int next_cost = now_cost + edge.second;
            if (costs[next] > next_cost) {
                costs[next] = next_cost;
                pq_mintop.push({next_cost, next});
            }
        }
    }
}

int main() {
    fastio;

    cin >> vertex >> edge >> start >> finish;

    edges.assign(vertex, vector<pii>());
    for (int i = 0; i < edge; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c}); // 양방향일 경우
    }

    dijkstra();

    return 0;
}
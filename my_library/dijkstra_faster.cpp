#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1e9;
const ll LLINF = 4e18;
int vertex, edge, start, finish;
vector<vector<pii> > edges;
vector<int> costs;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    costs.assign(vertex, INF);
    costs[start] = 0;
    pq_mintop.push({ 0, start });

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
                pq_mintop.push({ next_cost, next });
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> vertex >> edge >> start >> finish;

    edges.assign(vertex, vector<pii>());
    for (int i = 0; i < edge; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({ v, c });
        edges[v].push_back({ u, c }); // 양방향일 경우
    }

    dijkstra();

    return 0;
}
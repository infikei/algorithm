#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321, MAX_VERTEX = 800;
int vertex, edge, v1, v2, route1, route2, ans;
vector<pii> cost[MAX_VERTEX + 1];
int dist[MAX_VERTEX + 1];

void input() {
    cin >> vertex >> edge;
    int a, b, c;
    for (int i = 0; i < edge; i++) {
        cin >> a >> b >> c;
        cost[a].push_back(make_pair(b, c));
        cost[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
}

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;

    for (int i = 1; i <= vertex; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;
    pq_mintop.push(make_pair(0, start));

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();

        int i_end = cost[now].size();
        for (int i = 0; i < i_end; i++) {
            int next = cost[now][i].first;
            int next_cost = cost[now][i].second;

            if (dist[next] > now_cost + next_cost) {
                dist[next] = now_cost + next_cost;
                pq_mintop.push(make_pair(dist[next], next));
            }
        }
    }
}

int main() {
    fastio;

    input();

    dijkstra(v1);
    route1 = min(dist[v2] + dist[1], INF);
    route2 = min(dist[v2] + dist[vertex], INF);

    dijkstra(v2);
    route1 = min(route1 + dist[vertex], INF);
    route2 = min(route2 + dist[1], INF);

    ans = min(route1, route2);
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
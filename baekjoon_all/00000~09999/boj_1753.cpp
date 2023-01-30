#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321, MAX_VERTEX = 20000;
int vertex, edge, start_node;
vector<pii> cost[MAX_VERTEX + 1];
int dist[MAX_VERTEX + 1];

void input() {
    cin >> vertex >> edge >> start_node;
    int u, v, w;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> w;
        cost[u].push_back(make_pair(v, w));
    }
}

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;

    for (int i = 1; i <= vertex; i++) {
        dist[i] = INF;
    }

    dist[start_node] = 0;
    pq_mintop.push(make_pair(0, start_node));

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

void print() {
    for (int i = 1; i <= vertex; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main() {
    fastio;

    input();
    dijkstra();
    print();

    return 0;
}
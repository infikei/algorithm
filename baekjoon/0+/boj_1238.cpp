#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 987654321;
int n, m, x;
vector<vector<pii> > edges, edges_reversed;
vector<int> cost_dp, cost_dp_reversed;

void dijkstra(vector<vector<pii> > &edges_vec, vector<int> &cost_dp_vec) {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    cost_dp_vec.assign(n + 1, INF);
    cost_dp_vec[x] = 0;
    pq_mintop.push(make_pair(0, x));

    while (!pq_mintop.empty()) {
        int now_node = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();
        if (now_cost > cost_dp_vec[now_node]) continue;

        int i_end = edges_vec[now_node].size();
        for (int i = 0; i < i_end; i++) {
            int next_node = edges_vec[now_node][i].first;
            int next_cost = edges_vec[now_node][i].second;
            if (cost_dp_vec[next_node] > now_cost + next_cost) {
                cost_dp_vec[next_node] = now_cost + next_cost;
                pq_mintop.push(make_pair(cost_dp_vec[next_node], next_node));
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m >> x;
    edges.assign(n + 1, vector<pii>(0));
    edges_reversed.assign(n + 1, vector<pii>(0));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back(make_pair(v, c));
        edges_reversed[v].push_back(make_pair(u, c));
    }

    dijkstra(edges, cost_dp);
    dijkstra(edges_reversed, cost_dp_reversed);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, cost_dp[i] + cost_dp_reversed[i]);
    }
    cout << ans << '\n';

    return 0;
}
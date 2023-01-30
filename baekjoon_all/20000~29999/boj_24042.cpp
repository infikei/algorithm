#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e12;
ll n, m;
vector<vector<pll> > edges;
vector<ll> cost_dp;

void dijkstra(ll start = 1) {
    priority_queue<pll, vector<pll>, greater<pll> > pq_mintop;
    cost_dp.assign(n + 1, INF);
    cost_dp[start] = 0;
    pq_mintop.push(make_pair(0, start));

    while (!pq_mintop.empty()) {
        ll now_node = pq_mintop.top().second;
        ll now_cost = pq_mintop.top().first;
        pq_mintop.pop();
        if (now_cost > cost_dp[now_node]) continue;
        ll now_cost_period = now_cost / m * m;

        int i_end = edges[now_node].size();
        for (int i = 0; i < i_end; i++) {
            ll next_node = edges[now_node][i].first;
            ll next_cost = now_cost_period + edges[now_node][i].second;
            while (next_cost < now_cost) {
                next_cost += m;
            }
            if (cost_dp[next_node] > next_cost) {
                cost_dp[next_node] = next_cost;
                pq_mintop.push(make_pair(next_cost, next_node));
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    edges.assign(n + 1, vector<pll>(0));
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        edges[u].push_back(make_pair(v, i));
        edges[v].push_back(make_pair(u, i));
    }

    dijkstra();

    cout << cost_dp[n] << '\n';

    return 0;
}
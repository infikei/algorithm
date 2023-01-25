#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int n, m, k;
vector<vector<pii> > edges;
vector<priority_queue<int> > cost_dp;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    cost_dp[1].push(0);
    pq_mintop.push({0, 1});

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();

        for (auto edge : edges[now]) {
            int next = edge.first;
            int next_cost = now_cost + edge.second;
            if ((int)(cost_dp[next].size()) < k) {
                cost_dp[next].push(next_cost);
                pq_mintop.push({next_cost, next});
            }
            else if (cost_dp[next].top() > next_cost) {
                cost_dp[next].pop();
                cost_dp[next].push(next_cost);
                pq_mintop.push({next_cost, next});
            }
        }
    }
}

int main() {
    fastio;

    // input
    cin >> n >> m >> k;
    edges.assign(n + 1, vector<pii>(0));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
    cost_dp.assign(n + 1, priority_queue<int>());

    // dijkstra
    dijkstra();

    // print result
    for (int i = 1; i <= n; i++) {
        cout << ((int)(cost_dp[i].size()) < k ? -1 : cost_dp[i].top()) << '\n';
    }

    return 0;
}
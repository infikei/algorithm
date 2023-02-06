#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;
using pi3 = pair<int, pii>;

const int INF = 1e9;
int n, m, k, s, d;
vector<vector<pii> > edges;
vector<vector<int> > cost_dp;
vector<int> extra_cost;

void dijkstra() {
    priority_queue<pi3, vector<pi3>, greater<pi3> > pq_mintop;
    cost_dp.assign(n + 1, vector<int>(n + 1, INF));
    cost_dp[s][0] = 0;
    pq_mintop.push({0, {0, s}});

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second.second;
        int now_cost = pq_mintop.top().second.first;
        int now_cnt = pq_mintop.top().first;
        pq_mintop.pop();
        if (cost_dp[now][now_cnt] < now_cost) continue;
        if (now_cnt >= n) break;

        for (auto edge : edges[now]) {
            int next = edge.first;
            int next_cost = now_cost + edge.second;
            int next_cnt = now_cnt + 1;
            if (cost_dp[next][next_cnt] > next_cost) {
                cost_dp[next][next_cnt] = next_cost;
                pq_mintop.push({next_cnt, {next_cost, next}});
            }
        }
    }
}

int main() {
    fastio;

    // input
    cin >> n >> m >> k >> s >> d;
    edges.assign(n + 1, vector<pii>(0));
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    extra_cost.assign(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> extra_cost[i];
    }

    // dijkstra
    dijkstra();

    // print result
    for (int i = 0; i <= k; i++) {
        int ans = INF;
        for (int j = 1; j < n; j++) {
            if (cost_dp[d][j] == INF) continue;
            cost_dp[d][j] += j * extra_cost[i];
            ans = min(ans, cost_dp[d][j]);
        }
        cout << ans << '\n';
    }

    return 0;
}
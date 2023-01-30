#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int n, m, start, finish;
vector<vector<pii> > cost_graph;
vector<vector<int> > route_dp;
vector<int> cost_dp;

void dijkstra(bool flag) {
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    cost_dp.assign(n, INF);
    cost_dp[start] = 0;
    pq_mintop.push(make_pair(0, start));
    if (flag) route_dp.assign(n, vector<int>(0)); // 다익스트라를 1번째 수행할 때 (즉, flag == true일 때) route 기록

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();
        if (now_cost > cost_dp[now]) continue;

        int i_end = cost_graph[now].size();
        for (int i = 0; i < i_end; i++) {
            int next = cost_graph[now][i].first;
            int next_cost = cost_graph[now][i].second;
            if (next_cost == INF) continue;
            if (cost_dp[next] > now_cost + next_cost) {
                cost_dp[next] = now_cost + next_cost;
                pq_mintop.push(make_pair(cost_dp[next], next));
                if (flag) {
                    route_dp[next].clear();
                    route_dp[next].push_back(now);
                }
            }
            else if (flag && cost_dp[next] == now_cost + next_cost) {
                route_dp[next].push_back(now);
            }
        }
    }
}

void remove_path() {
    queue<int> q;
    vector<vector<bool> > visited;
    visited.assign(n, vector<bool>(n, false));
    q.push(finish);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto prev : route_dp[now]) {
            if (visited[prev][now]) continue;
            visited[prev][now] = true;
            int i_end = cost_graph[prev].size();
            for (int i = 0; i < i_end; i++) {
                if (cost_graph[prev][i].first == now) {
                    cost_graph[prev][i].second = INF;
                    break;
                }
            }
            q.push(prev);
        }
    }
}

int main() {
    fastio;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> start >> finish;
        cost_graph.assign(n, vector<pii>(0));
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            cost_graph[u].push_back(make_pair(v, p));
        }

        dijkstra(true);
        remove_path();
        dijkstra(false);
        cout << (cost_dp[finish] == INF ? -1 : cost_dp[finish]) << '\n';
    }

    return 0;
}
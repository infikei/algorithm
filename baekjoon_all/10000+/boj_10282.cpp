// Solve 2023-11-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pii>> edges(n + 1, vector<pii>());

        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;

            edges[b].emplace_back(a, s);
        }

        vector<int> costs(n + 1, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq_mintop;
        costs[c] = 0;
        pq_mintop.emplace(0, c);

        while (!pq_mintop.empty()) {
            int now = pq_mintop.top().second;
            int cost_to_now = pq_mintop.top().first;
            pq_mintop.pop();

            if (costs[now] < cost_to_now) continue;

            for (pii edge : edges[now]) {
                int next = edge.first;
                int cost_to_next = cost_to_now + edge.second;

                if (costs[next] > cost_to_next) {
                    costs[next] = cost_to_next;
                    pq_mintop.emplace(cost_to_next, next);
                }
            }
        }

        int cnt_infected_computer = 0;
        int max_cost = 0;

        for (int u = 1; u <= n; u++) {
            if (costs[u] == INF) continue;

            cnt_infected_computer++;
            max_cost = max(max_cost, costs[u]);
        }

        cout << cnt_infected_computer << ' ' << max_cost << '\n';
    }

    return 0;
}

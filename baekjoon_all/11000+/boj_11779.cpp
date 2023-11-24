// Solve 2023-01-23
// Update 2023-11-24

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

    int n, m;
    cin >> n >> m;

    vector<vector<pii> > buses(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        buses[from].emplace_back(to, cost);
    }

    int s, e;
    cin >> s >> e;

    vector<int> costs(n + 1, INF);
    vector<int> previous_city(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    costs[s] = 0;
    pq_mintop.emplace(0, s);

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int cost_to_now = pq_mintop.top().first;
        pq_mintop.pop();

        if (now == e) break;
        if (costs[now] < cost_to_now) continue;

        for (pii bus : buses[now]) {
            int next = bus.first;
            int cost_to_next = cost_to_now + bus.second;

            if (costs[next] > cost_to_next) {
                costs[next] = cost_to_next;
                previous_city[next] = now;
                pq_mintop.emplace(cost_to_next, next);
            }
        }
    }

    vector<int> route;
    int pos = e;

    while (pos != -1) {
        route.push_back(pos);
        pos = previous_city[pos];
    }

    cout << costs[e] << '\n';
    cout << SIZE(route) << '\n';

    for (auto it = route.rbegin(); it != route.rend(); it++) {
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}

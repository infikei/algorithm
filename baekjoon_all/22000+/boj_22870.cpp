// Solve 2023-01-28
// Update 2023-06-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9, N_MAX = 200001;
int n, start, finish, ans;
vector<pii> edges[N_MAX];
int costs[N_MAX];
bool removed_vertexes[N_MAX];

void dijkstra(int s, int e) {
    for (int i = 1; i <= n; i++) {
        costs[i] = INF;
    }
    costs[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    pq_mintop.push({ 0, s });

    while (!pq_mintop.empty()) {
        int now = pq_mintop.top().second;
        int now_cost = pq_mintop.top().first;
        pq_mintop.pop();
        if (now == e) break;
        if (now_cost != costs[now]) continue;

        for (auto &edge : edges[now]) {
            int next = edge.first;
            int next_cost = edge.second;
            if (removed_vertexes[next]) continue;
            if (costs[next] > now_cost + next_cost) {
                costs[next] = now_cost + next_cost;
                pq_mintop.push({ costs[next], next });
            }
        }
    }
}

void remove_vertexes() {
    int now = start, now_cost = 0;
    removed_vertexes[start] = true;

    while (now != finish) {
        for (auto &edge : edges[now]) {
            int next = edge.first, now_to_next = edge.second;
            if (now_cost + now_to_next + costs[next] == ans) {
                now = next;
                now_cost += now_to_next;
                removed_vertexes[next] = true;
                break;
            }
        }
    }

    removed_vertexes[start] = removed_vertexes[finish] = false;
}

int main() {
    FASTIO;

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b ,c;
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }
    for (int i = 1; i <= n; i++) {
        sort(ALL(edges[i]));
    }

    cin >> start >> finish;

    dijkstra(finish, start);
    ans = costs[start];
    remove_vertexes();

    dijkstra(start, finish);
    ans += costs[finish];
    cout << ans << '\n';

    return 0;
}

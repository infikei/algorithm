// Solve 2025-10-18

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Node{
    int to, time, cost;

    Node(int to, int time, int cost) : to(to), time(time), cost(cost) {
    }

    bool operator<(const Node& rhs) const {
        if (cost != rhs.cost) return cost > rhs.cost;
        return time > rhs.time;
    }
};

vector<Node> adj[101];
int min_time[101];

int main() {
    FASTIO;

    int n, time_lim, money_lim, n_road;
    cin >> n >> time_lim >> money_lim >> n_road;

    for (int i = 0; i < n_road; i++) {
        int u, v, dt, cost;
        cin >> u >> v >> dt >> cost;
        adj[u].emplace_back(v, dt, cost);
        adj[v].emplace_back(u, dt, cost);
    }

    priority_queue<Node> pq;
    memset(min_time, 0x3f, sizeof min_time);
    pq.emplace(1, 0, 0);

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.to == n) {
            cout << cur.cost << '\n';
            return 0;
        }

        min_time[cur.to] = cur.time;

        for (Node& nxt : adj[cur.to]) {
            int nxt_node = nxt.to;
            int nxt_time = cur.time + nxt.time;
            int nxt_cost = cur.cost + nxt.cost;

            if (nxt_time <= time_lim && nxt_cost <= money_lim && nxt_time < min_time[nxt_node]) {
                pq.emplace(nxt_node, nxt_time, nxt_cost);
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}

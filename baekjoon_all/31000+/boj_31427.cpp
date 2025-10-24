// Solve 2025-10-21

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

vector<pii> edges[5];
unordered_map<string, vector<int>> mst_edge_cnt;
int seq[5];
bool selected[5];
int parent[50001];

int get_parent_of(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = get_parent_of(parent[u]);
}

void union_parents(int u, int v) {
    u = get_parent_of(u);
    v = get_parent_of(v);

    if (u != v) {
        if (parent[u] > parent[v]) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }
}

vector<int> kruskal() {
    vector<int> edge_cnt(5, 0);
    memset(parent, -1, sizeof parent);

    for (int i = 0; i < 5; i++) {
        int edge_type = seq[i];

        for (pii& edge : edges[edge_type]) {
            int u = edge.first;
            int v = edge.second;
            u = get_parent_of(u);
            v = get_parent_of(v);

            if (u != v) {
                union_parents(u, v);
                edge_cnt[edge_type]++;
            }
        }
    }

    return edge_cnt;
}

string get_order_str() {
    string ret;

    for (int x : seq) {
        ret += to_string(x) + ",";
    }

    ret.pop_back();
    return ret;
}

string get_order_str_2(vector<pii>& v) {
    string ret;

    for (pii& x : v) {
        ret += to_string(x.second) + ",";
    }

    ret.pop_back();
    return ret;
}

void recur(int depth) {
    if (depth == 5) {
        vector<int> edge_cnt = kruskal();
        mst_edge_cnt[get_order_str()] = edge_cnt;
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (selected[i]) continue;

        selected[i] = true;
        seq[depth] = i;
        recur(depth + 1);
        selected[i] = false;
    }
}

int main() {
    FASTIO;

    int n, m, q;
    cin >> n >> m >> q;

    while (m-- > 0) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        edges[c - 'A'].emplace_back(u, v);
    }

    recur(0);

    while (q-- > 0) {
        int edge_cost[5];
        vector<pii> cost_and_type;

        for (int i = 0; i < 5; i++) {
            cin >> edge_cost[i];
            cost_and_type.emplace_back(edge_cost[i], i);
        }

        sort(cost_and_type.begin(), cost_and_type.end());
        vector<int> edge_cnt = mst_edge_cnt[get_order_str_2(cost_and_type)];
        ll ans = 0;

        for (int i = 0; i < 5; i++) {
            ans += (ll) edge_cost[i] * edge_cnt[i];
        }

        cout << ans << '\n';
    }

    return 0;
}

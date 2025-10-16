// Solve 2025-10-15

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

int n;
int card[1001];
int m, k;
vector<pii> adj[501];
int memo[1001][501];

int recur(int card_num, int cur_node) {
    if (card_num > n) {
        return 0;
    }

    if (memo[card_num][cur_node] != -1) {
        return memo[card_num][cur_node];
    }

    int cur_card_color = card[card_num];
    int mx = 0;

    for (pii& p : adj[cur_node]) {
        int nxt_node = p.first;
        int nxt_edge_color = p.second;
        int res = recur(card_num + 1, nxt_node) + (cur_card_color == nxt_edge_color ? 10 : 0);
        mx = max(mx, res);
    }

    memo[card_num][cur_node] = mx;
    return mx;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        card[i] = c - 'A';
    }

    cin >> m >> k;

    for (int i = 0; i < k; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c - 'A');
        adj[v].emplace_back(u, c - 'A');
    }

    memset(memo, -1, sizeof memo);
    cout << recur(1, 1) << '\n';
    return 0;
}

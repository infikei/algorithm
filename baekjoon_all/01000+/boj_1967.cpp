// Solve 2023-02-13
// Update 2025-10-04

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

pii dfs(int cur, vector<vector<pii>>& tree) {
    vector<int> max_depth_list = {0, 0};
    int max_len = 0;

    for (pii& p : tree[cur]) {
        int nxt = p.first;
        int w = p.second;

        pii nxt_res = dfs(nxt, tree);
        max_depth_list.push_back(nxt_res.first + w);
        max_len = max(max_len, nxt_res.second);
    }

    sort(max_depth_list.begin(), max_depth_list.end(), greater<int>());
    return {max_depth_list[0], max(max_depth_list[0] + max_depth_list[1], max_len)};
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<vector<pii>> tree(n + 1);

    for (int i = 1; i < n; i++) {
        int par, child, w;
        cin >> par >> child >> w;
        tree[par].emplace_back(child, w);
    }

    pii res = dfs(1, tree);
    cout << res.second << '\n';
    return 0;
}

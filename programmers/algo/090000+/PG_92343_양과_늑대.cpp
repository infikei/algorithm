// Solve 2025-10-11

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 1000000000;

int ans;

void dfs(int cur, int selected, int sheep, int wolf, vector<int>& info, vector<vector<int>>& adj) {
    if (sheep <= wolf) return;

    ans = max(ans, sheep);

    for (int u = 0; u < size(info); u++) {
        if (!(selected & (1 << u))) continue;

        for (int nxt : adj[u]) {
            if (selected & (1 << nxt)) continue;

            int n_selected = (selected | (1 << nxt));
            int n_sheep = sheep + (info[nxt] == 0);
            int n_wolf = wolf + (info[nxt] == 1);
            dfs(cur, n_selected, n_sheep, n_wolf, info, adj);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    ans = 0;
    int n = size(info);
    vector<vector<int>> adj(n);

    for (vector<int>& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    dfs(0, 1, 1, 0, info, adj);
    return ans;
}

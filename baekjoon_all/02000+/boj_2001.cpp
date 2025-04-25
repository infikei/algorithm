// Solve 2025-04-23

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool visited[101][1 << 15];
int island_to_jewel[101];

struct AdjEdge{
    int to;
    int limit;

    AdjEdge(int to, int limit) : to(to), limit(limit) {
    }
};

struct IslandVisitInfo{
    int island_num;
    int jewels;

    IslandVisitInfo(int island_num, int jewels) : island_num(island_num), jewels(jewels) {
    }
};

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++) {
        int island_num;
        cin >> island_num;

        island_to_jewel[island_num] = i;
    }

    vector<vector<AdjEdge>> adj(n + 1, vector<AdjEdge>());

    for (int i = 0; i < m; i++) {
        int from, to, limit;
        cin >> from >> to >> limit;

        adj[from].emplace_back(to, limit);
        adj[to].emplace_back(from, limit);
    }

    int ans = 0;
    queue<IslandVisitInfo> bfs_que;
    visited[1][0] = true;
    bfs_que.emplace(1, 0);

    while (!bfs_que.empty()) {
        IslandVisitInfo cur = bfs_que.front();
        bfs_que.pop();

        int cur_jewels_cnt = __builtin_popcount(cur.jewels);

        if (cur.island_num == 1) {
            ans = max(ans, cur_jewels_cnt);
        }

        if (island_to_jewel[cur.island_num] != 0) {
            int nxt_jewels = cur.jewels | (1 << island_to_jewel[cur.island_num]);

            if (!visited[cur.island_num][nxt_jewels]) {
                visited[cur.island_num][nxt_jewels] = true;
                bfs_que.emplace(cur.island_num, nxt_jewels);
            }
        }

        for (AdjEdge &edge : adj[cur.island_num]) {
            if (cur_jewels_cnt <= edge.limit && !visited[edge.to][cur.jewels]) {
                visited[edge.to][cur.jewels] = true;
                bfs_que.emplace(edge.to, cur.jewels);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

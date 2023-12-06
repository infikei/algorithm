// Solve 2023-12-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, s, e;
    cin >> n >> s >> e;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> val(n + 1, 0);
    queue<int> bfs_que;
    int bfs_depth = 0;
    val[s] = 1;
    bfs_que.push(s);

    while (!bfs_que.empty()) {
        bfs_depth++;
        int iter = 0;
        int max_iter = SIZE(bfs_que);

        while (iter < max_iter) {
            iter++;

            int cur = bfs_que.front();
            bfs_que.pop();

            int next_size = SIZE(adj[cur]);

            if (bfs_depth >= 2) {
                next_size--;
            }

            int next_val = val[cur];

            // 짝수 번째 이동에서 자식 노드가 두 개 이상인 경우 후공을 선택해야 한다.
            if (bfs_depth % 2 == 0 && next_size >= 2) {
                next_val = 2;
            }

            for (int next : adj[cur]) {
                if (val[next] == 0) {
                    val[next] = next_val;
                    bfs_que.push(next);
                }
            }
        }
    }

    if (val[e] == 1) {
        cout << "First\n";
    }
    else {
        cout << "Second\n";
    }

    return 0;
}

// Solve 2023-01-10
// Update 2023-11-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<int> > edges(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        edges[from].push_back(to);
    }

    queue<int> bfs_que;
    bfs_que.push(x);
    vector<bool> visited(n + 1, false);
    visited[x] = true;
    int iter = 0;

    while (!bfs_que.empty() && iter < k) {
        for (int i = 0, ie = SIZE(bfs_que); i < ie; i++) {
            int now = bfs_que.front();
            bfs_que.pop();

            for (int next : edges[now]) {
                if (visited[next]) continue;

                visited[next] = true;
                bfs_que.push(next);
            }
        }

        iter++;
    }

    vector<int> ans_vec;

    while (!bfs_que.empty()) {
        ans_vec.push_back(bfs_que.front());
        bfs_que.pop();
    }

    sort(ans_vec.begin(), ans_vec.end());

    if (ans_vec.empty()) {
        cout << -1 << '\n';
    }
    else {
        for (int ans : ans_vec) {
            cout << ans << '\n';
        }
    }

    return 0;
}

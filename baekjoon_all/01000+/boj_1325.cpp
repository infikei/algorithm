// Solve 2024-02-04
// Update 2025-03-03

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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int max_hack = 0;
    vector<int> max_hack_idx;
    bool visited[10001];

    for (int u = 1; u <= n; u++) {
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }

        queue<int> bfs_que;
        bfs_que.push(u);
        visited[u] = true;
        int cur_hack = 1;

        while (!bfs_que.empty()) {
            int now = bfs_que.front();
            bfs_que.pop();

            for (int next : adj[now]) {
                if (visited[next]) continue;

                visited[next] = true;
                bfs_que.push(next);
                cur_hack++;
            }
        }

        if (cur_hack > max_hack) {
            max_hack = cur_hack;
            max_hack_idx = vector<int>();
            max_hack_idx.push_back(u);
        }
        else if (cur_hack == max_hack) {
            max_hack_idx.push_back(u);
        }
    }

    for (int u : max_hack_idx) {
        cout << u << ' ';
    }

    cout << '\n';

    return 0;
}

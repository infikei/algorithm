// Solve 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Node{
    int num, depth;
    Node(int n, int d) : num(n), depth(d) {}
};

int main() {
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int> > adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }

    vector<int> visited(n + 1, -1);
    stack<Node> stck;

    stck.push({ r, 0 });

    while (!stck.empty()) {
        Node now = stck.top();
        stck.pop();

        if (visited[now.num] != -1) continue;

        visited[now.num] = now.depth;
        int next_depth = now.depth + 1;

        for (int &next_num : adj[now.num]) {
            if (visited[next_num] != -1) continue;

            stck.push({ next_num, next_depth });
        }
    }

    for (int u = 1; u <= n; u++) {
        cout << visited[u] << '\n';
    }

    return 0;
}

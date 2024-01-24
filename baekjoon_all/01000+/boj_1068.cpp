// Solve 2024-01-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int>> children(n, vector<int>());
    int root_node = -1;

    for (int u = 0; u < n; u++) {
        int parent;
        cin >> parent;

        if (parent == -1) {
            root_node = u;
        }
        else {
            children[parent].push_back(u);
        }
    }

    int erased_node;
    cin >> erased_node;

    int ans = 0;
    queue<int> bfs_que;

    if (root_node != erased_node) {
        bfs_que.push(root_node);
    }

    while (!bfs_que.empty()) {
        int cur_node = bfs_que.front();
        bfs_que.pop();

        if (children[cur_node].empty()) {
            ans++;
        }
        else if (SIZE(children[cur_node]) == 1 && children[cur_node][0] == erased_node) {
            ans++;
        }
        else {
            for (int child : children[cur_node]) {
                if (child != erased_node) {
                    bfs_que.push(child);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

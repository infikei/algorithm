#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, m, k, x;
vector<vector<int> > edge;
vector<int> ans;

void bfs() {
    vector<bool> visited;
    visited.assign(n + 1, false);
    visited[x] = true;
    queue<int> q;
    q.push(x);

    int iter = 0;
    while (!q.empty() && iter < k) {
        int i_end = q.size();
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();

            for (auto next : edge[now]) {
                if (visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
        iter++;
    }

    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
}

int main() {
    fastio;

    cin >> n >> m >> k >> x;
    edge.assign(n + 1, vector<int>(0, 0));
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
    }

    bfs();

    if (ans.empty()) cout << -1 << '\n';
    else {
        sort(ans.begin(), ans.end());
        for (auto a : ans) cout << a << '\n';
    }

    return 0;
}
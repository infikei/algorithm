#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int N_MAX = 100;
int n, target0, target1, ans;
vector<int> graph[N_MAX + 1];

void bfs() {
    queue<int> q;
    q.push(target0);
    bool visited[N_MAX + 1] = {false};
    visited[target0] = true;

    while (!q.empty()) {
        int i_end = (int)q.size();
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();
            for (auto next : graph[now]) {
                if (visited[next]) continue;
                visited[next] = true;
                if (next == target1) {
                    ans++;
                    return;
                }
                q.push(next);
            }
        }
        ans++;
    }
    ans = -1;
}

int main() {
    FASTIO;

    int m;
    cin >> n >> target0 >> target1 >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();
    cout << ans << '\n';

    return 0;
}
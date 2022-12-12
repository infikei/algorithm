#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using vint = vector<int>;
using vvint = vector<vint>;

int V, E;
bool ans;
vvint graph;
vint visited;

void dfs(int now) {
    for (auto next : graph[now]) {
        if (visited[next] > 0) {
            if (visited[next] == visited[now]) {
                ans = false;
                return;
            }
            continue;
        }
        visited[next] = 3 - visited[now]; // visited[now]가 1이면 visited[next]를 2로, visited[now]가 2이면 visited[next]를 1로 설정하는 것이다.
        dfs(next);
        if (!ans) {
            return;
        }
    }
}

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> V >> E;

        ans = true;
        graph.assign(V + 1, vint(0, 0));
        visited.assign(V + 1, 0);

        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (visited[i] > 0) {
                continue;
            }

            visited[i] = 1;
            dfs(i);
            if (!ans) {
                break;
            }
        }

        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
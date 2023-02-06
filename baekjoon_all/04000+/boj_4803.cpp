#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int> >;

int N, M, cnt;
vvint graph;
vint visited;

bool dfs(int now, int prev = -1) {
    bool isTree = true;

    for (auto next : graph[now]) {
        if (next == prev) continue;
        if (visited[next] > 0) {
            isTree = false;
            continue;
        }
        visited[next] = 1;
        if (!dfs(next, now)) isTree = false;
    }

    return isTree;
}

int main() {
    fastio;

    int testcase = 0;
    while (true) {
        testcase++;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        // initialize
        graph.assign(N + 1, vint(0, 0));
        visited.assign(N + 1, 0);
        cnt = 0;

        // input edges
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // dfs
        for (int i = 1; i <= N; i++) {
            if (visited[i] > 0) continue;
            visited[i] = 1;
            if (dfs(i)) cnt++;
        }

        // print result
        if (cnt > 1) cout << "Case " << testcase << ": A forest of " << cnt << " trees.\n";
        else if (cnt == 1) cout << "Case " << testcase << ": There is one tree.\n";
        else cout << "Case " << testcase << ": No trees.\n";
    }

    return 0;
}
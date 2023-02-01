#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int> > costs;

void floyd_warshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (costs[j][i] != INF && costs[i][k] != INF) {
                    costs[j][k] = min(costs[j][k], costs[j][i] + costs[i][k]);
                }
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    costs.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) costs[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        costs[u][v] = 0;
        if (b == 1) costs[v][u] = 0;
        else costs[v][u] = 1;
    }

    floyd_warshall();

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;
        cout << costs[s][e] << '\n';
    }

    return 0;
}
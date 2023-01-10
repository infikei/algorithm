#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321;
int v, e, ans;
vector<vector<int> > cost_dp;

void floyd_warshall() {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                if (cost_dp[j][i] != INF && cost_dp[i][k] != INF) {
                    cost_dp[j][k] = min(cost_dp[j][k], cost_dp[j][i] + cost_dp[i][k]);
                }
            }
        }
    }
}

int main() {
    fastio;

    cin >> v >> e;
    cost_dp.assign(v + 1, vector<int>(v + 1, INF));
    for (int i = 1; i <= v; i++) cost_dp[i][i] = 0;
    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        cost_dp[from][to] = min(cost_dp[from][to], cost);
    }

    floyd_warshall();

    ans = INF;
    for (int i = 1; i <= v; i++) {
        for (int j = i + 1; j <= v; j++) {
            if (cost_dp[i][j] != INF && cost_dp[j][i] != INF) {
                ans = min(ans, cost_dp[i][j] + cost_dp[j][i]);
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}
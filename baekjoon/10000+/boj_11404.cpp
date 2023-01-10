#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321;
int n, m;
vector<vector<int> > cost_dp;

void floyd_warshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (cost_dp[j][i] != INF && cost_dp[i][k] != INF) {
                    cost_dp[j][k] = min(cost_dp[j][k], cost_dp[j][i] + cost_dp[i][k]);
                }
            }
        }
    }
}

void input() {
    cin >> n >> m;
    cost_dp.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) cost_dp[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        cost_dp[from][to] = min(cost_dp[from][to], cost);
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (cost_dp[i][j] == INF ? 0 : cost_dp[i][j]) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastio;

    input();

    floyd_warshall();

    print();

    return 0;
}
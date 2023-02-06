#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321;
int n, m;
vector<vector<int> > cost_dp, route;
vector<int> now_route;

void floyd_warshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (cost_dp[j][i] == INF || cost_dp[i][k] == INF) continue;
                if (cost_dp[j][k] > cost_dp[j][i] + cost_dp[i][k]) {
                    cost_dp[j][k] = cost_dp[j][i] + cost_dp[i][k];
                    route[j][k] = i;
                }
            }
        }
    }
}

void find_route(int s, int e) {
    if (route[s][e] == 0) {
        now_route.push_back(s);
        now_route.push_back(e);
        return;
    }
    find_route(s, route[s][e]);
    now_route.pop_back();
    find_route(route[s][e], e);
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
    route.assign(n + 1, vector<int>(n + 1, 0));
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (cost_dp[i][j] == INF ? 0 : cost_dp[i][j]) << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost_dp[i][j] == INF || i == j) {
                cout << 0 << '\n';
                continue;
            }
            now_route.clear();
            find_route(i, j);
            cout << now_route.size() << ' ';
            for (auto a : now_route) cout << a << ' ';
            cout << '\n';
        }
    }
}

int main() {
    fastio;

    input();

    floyd_warshall();

    print();

    return 0;
}
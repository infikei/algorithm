#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321;
int n, m, k;
vector<vector<int> > cost_dp;
vector<int> friends_city, ans_city;

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
    for (int i = 1; i <= n; i++) {
        cost_dp[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        cost_dp[from][to] = min(cost_dp[from][to], cost);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        friends_city.push_back(c);
    }
}

void find_answer() {
    int min_max_cost = INF;
    for (int i = 1; i <= n; i++) {
        int max_cost = 0;
        for (auto a : friends_city) {
            if (cost_dp[a][i] == INF || cost_dp[i][a] == INF) {
                max_cost = INF;
                break;
            }
            max_cost = max(max_cost, cost_dp[a][i] + cost_dp[i][a]);
        }
        if (min_max_cost > max_cost) {
            min_max_cost = max_cost;
            ans_city.clear();
        }
        if (min_max_cost == max_cost) {
            ans_city.push_back(i);
        }
    }

    sort(ans_city.begin(), ans_city.end());
}

int main() {
    fastio;

    input();

    floyd_warshall();

    find_answer();

    for (auto a : ans_city) cout << a << ' ';
    cout << '\n';

    return 0;
}
#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 100, MAX_M = 10000000, MAX_MEMORY = 10000000, MAX_COST = 100;
int n, m, ans, memory[MAX_N + 1], cost[MAX_N + 1], sum_cost;
int dp[MAX_N + 1][MAX_COST * MAX_N + 1];

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> memory[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        sum_cost += cost[i];
    }

    // dp 배열 : i번째 앱까지 확인했을 때 j의 비용으로 확보할 수 있는 최대한의 메모리를 저장하는 배열
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < cost[i]; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = cost[i]; j <= sum_cost; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
        }
    }

    for (int i = 0; i <= sum_cost; i++) {
        if (dp[n][i] >= m) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
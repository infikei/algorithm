// Solve 2023-01-05
// Update 2023-11-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int memory[101];

    for (int i = 1; i <= n; i++) {
        cin >> memory[i];
    }

    int cost[101];
    int cost_sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];

        cost_sum += cost[i];
    }

    // dp 배열 : app번째 앱까지 확인했을 때 c의 비용으로 확보할 수 있는 최대한의 메모리를 저장하는 배열
    vector<vector<int>> dp(101, vector<int>(10100, 0));

    for (int app = 1; app <= n; app++) {
        for (int c = 0; c < cost[app]; c++) {
            dp[app][c] = dp[app - 1][c];
        }

        for (int c = cost[app]; c <= cost_sum; c++) {
            dp[app][c] = max(dp[app - 1][c], dp[app - 1][c - cost[app]] + memory[app]);
        }
    }

    int ans = 0;

    for (int c = 0; c <= cost_sum; c++) {
        if (dp[n][c] >= m) {
            ans = c;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}

#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int INF = 987654321;
int n, m, r, ans;
vector<vector<int> > dist_dp;
vector<int> items;

void floyd_warshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dist_dp[j][i] == INF || dist_dp[i][k] == INF) continue;
                dist_dp[j][k] = min(dist_dp[j][k], dist_dp[j][i] + dist_dp[i][k]);
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m >> r;
    items.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }
    dist_dp.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dist_dp[i][i] = 0;
    }
    for (int i = 0; i < r; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;
        dist_dp[a][b] = min(dist_dp[a][b], dist);
        dist_dp[b][a] = min(dist_dp[b][a], dist);
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dist_dp[i][j] <= m) {
                cnt += items[j];
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';

    return 0;
}
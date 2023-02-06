#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, k, ans;
vector<vector<int> > dist_dp;
vector<bool> visited;

void floyd_warshall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist_dp[j][k] = min(dist_dp[j][k], dist_dp[j][i] + dist_dp[i][k]);
            }
        }
    }
}

void dfs(int now = k, int now_dist = 0, int depth = 1) {
    if (depth == n) {
        ans = min(ans, now_dist);
        return;
    }
    if (now_dist > ans) return;

    for (int next = 0; next < n; next++) {
        if (visited[next]) continue;

        visited[next] = true;
        dfs(next, now_dist + dist_dp[now][next], depth + 1);
        visited[next] = false;
    }
}

int main() {
    fastio;

    cin >> n >> k;
    dist_dp.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist_dp[i][j];
        }
    }

    floyd_warshall();

    visited.assign(n, false);
    visited[k] = true;
    ans = 1000000;
    dfs();
    cout << ans << '\n';

    return 0;
}
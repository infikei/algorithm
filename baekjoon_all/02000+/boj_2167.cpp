// Solve 2022-07-06
// Update 2023-07-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[301][301];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;

            dp[i][j] = -dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] + x;
        }
    }

    int k;
    cin >> k;

    for (int ki = 0; ki < k; ki++) {
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;

        cout << dp[xs - 1][ys - 1] - dp[xs - 1][ye] - dp[xe][ys - 1] + dp[xe][ye] << '\n';
    }

    return 0;
}

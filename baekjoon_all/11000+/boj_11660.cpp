// Solve 2022-07-22
// Update 2023-07-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[1025][1025];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            int x;
            cin >> x;

            dp[row][col] = x + dp[row][col - 1] - dp[row - 1][col - 1] + dp[row - 1][col];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] << '\n';
    }

    return 0;
}

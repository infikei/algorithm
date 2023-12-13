// Solve 2022-09-09
// Update 2023-12-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dp[2][100000];

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dp[i][j];
            }
        }

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];

        for (int j = 2; j < n; j++) {
            dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
            dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}

// Solve 2022-07-02
// Update 2023-07-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1e9;
int dp[2][10];

int main() {
    FASTIO;

    int prow = 0, nrow = 1;
    for (int j = 1; j <= 9; j++) {
        dp[prow][j] = 1;
    }

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        dp[nrow][0] = dp[prow][1];
        dp[nrow][9] = dp[prow][8];

        for (int j = 1; j <= 8; j++) {
            dp[nrow][j] = (dp[prow][j - 1] + dp[prow][j + 1]) % MOD;
        }

        swap(prow, nrow);
    }

    int ans = 0;
    for (int j = 0; j <= 9; j++) {
        ans += dp[prow][j];
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}

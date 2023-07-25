// Solve 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000009;
int dp[1001][1003];

int main() {
    FASTIO;

    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;

    dp[2][1] = 1;
    dp[2][2] = 2;
    dp[2][3] = 2;
    dp[2][4] = 2;

    dp[3][1] = 1;
    dp[3][2] = 3;
    dp[3][3] = 4;
    dp[3][4] = 4;
    dp[3][5] = 4;

    for (int i = 4; i < 1001; i++) {
        for (int j = (i + 2) / 3; j <= i; j++) {
            dp[i][j] = ((dp[i - 3][j - 1] + dp[i - 2][j - 1]) % MOD + dp[i - 1][j - 1]) % MOD;
        }

        dp[i][i + 2] = dp[i][i + 1] = dp[i][i];
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, m;
        cin >> n >> m;

        cout << dp[n][m] << '\n';
    }

    return 0;
}

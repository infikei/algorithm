// Solve 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000009;
int dp[100001][2];

int main() {
    FASTIO;

    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 2;
    dp[3][1] = 2;

    for (int i = 4; i < 100001; i++) {
        dp[i][0] = ((dp[i - 3][1] + dp[i - 2][1]) % MOD + dp[i - 1][1]) % MOD;
        dp[i][1] = ((dp[i - 3][0] + dp[i - 2][0]) % MOD + dp[i - 1][0]) % MOD;
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }

    return 0;
}

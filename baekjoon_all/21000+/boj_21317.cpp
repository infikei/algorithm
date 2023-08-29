// Solve 2022-08-01
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int small_jump[21], big_jump[21], very_big_jump;

    for (int i = 1; i < n; i++) {
        cin >> small_jump[i] >> big_jump[i];
    }

    cin >> very_big_jump;

    int dp[21][2] = { 0 };

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + small_jump[i - 1];

        if (i <= 2) continue;
        dp[i][0] = min(dp[i][0], dp[i - 2][0] + big_jump[i - 2]);

        if (i <= 3) continue;
        dp[i][1] = dp[i - 3][0] + very_big_jump;

        if (i <= 4) continue;
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + small_jump[i - 1]);

        if (i <= 5) continue;
        dp[i][1] = min(dp[i][1], dp[i - 2][1] + big_jump[i - 2]);
    }

    if (n >= 4) {
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
    else {
        cout << dp[n][0] << '\n';
    }

    return 0;
}

// Solve 2022-06-03
// Update 2023-07-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int stairs[301];
int dp[301][2];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    dp[1][0] = stairs[1];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stairs[i];
        dp[i][1] = dp[i - 1][0] + stairs[i];
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}

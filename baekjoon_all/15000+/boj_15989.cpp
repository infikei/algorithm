// Solve 2022-10-22
// Update 2023-07-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[10001][2];

int main() {
    FASTIO;

    dp[2][0] = 1;

    for (int i = 3; i < 10001; i++) {
        dp[i][0] = 1 + dp[i - 2][0];
        dp[i][1] = 1 + dp[i - 3][0] + dp[i - 3][1];
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        cout << 1 + dp[n][0] + dp[n][1] << '\n';
    }

    return 0;
}

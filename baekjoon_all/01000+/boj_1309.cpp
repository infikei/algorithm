// Solve 2023-07-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 9901;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int dp[2] = { 0, 1 };
    for (int i = 1; i <= n; i++) {
        dp[1] += dp[0];
        dp[0] += dp[1];
        swap(dp[0], dp[1]);

        dp[0] %= MOD;
        dp[1] %= MOD;
    }

    cout << (dp[0] * 2 + dp[1]) % MOD << '\n';

    return 0;
}

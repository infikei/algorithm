// Solve 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 1000000007;

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll dp[3] = { 1, 2, 3 };

    for (int i = 5; i <= n; i++) {
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = (dp[0] + dp[1]) % MOD;
    }

    cout << dp[2] << ' ' << n - 2 << '\n';

    return 0;
}

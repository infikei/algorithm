// Solve 2022-06-28
// Update 2023-07-21

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

    ll dp[3] = { 0, 0, 1 };
    for (int i = 2; i <= n; i++) {
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[0] + dp[1];
    }

    cout << dp[2] << '\n';

    return 0;
}

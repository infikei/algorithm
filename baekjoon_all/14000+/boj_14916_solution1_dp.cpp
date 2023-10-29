// Solve 2022-07-26
// Update 2023-10-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dp[100001] = { 0, -1, 1, -1, 2, 1, 3, 2, 4 };

    int n;
    cin >> n;

    for (int i = 9; i <= n; i++) {
        dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
    }

    cout << dp[n] << '\n';

    return 0;
}

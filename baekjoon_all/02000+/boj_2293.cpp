// Solve 2022-09-17
// Update 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[10001] = { 1 };

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;

        for (int j = coin; j <= k; j++) {
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}

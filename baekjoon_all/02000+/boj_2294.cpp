// Solve 2022-09-17
// Update 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;
int dp[10001];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int j = 1; j <= k; j++) {
        dp[j] = INF;
    }

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;

        for (int j = coin; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[k] == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[k] << '\n';
    }

    return 0;
}

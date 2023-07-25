// Solve 2022-10-17
// Update 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 10007;
int dp[10];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[i] = 1;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 9; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j];
            }
            dp[i] %= MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[i];
    }
    ans %= MOD;

    cout << ans << '\n';

    return 0;
}

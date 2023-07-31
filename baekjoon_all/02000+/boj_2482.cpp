// Solve 2023-07-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000003;
int dp[1001][1001];

int main() {
    FASTIO;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int nn = 2; nn <= 1000; nn++) {
        dp[nn][0] = 1;

        int kk_end = (nn + 1) >> 1;
        for (int kk = 1; kk <= kk_end; kk++) {
            dp[nn][kk] = (dp[nn - 2][kk - 1] + dp[nn - 1][kk]) % MOD;
        }
    }

    int n, k;
    cin >> n >> k;

    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD << '\n';

    return 0;
}

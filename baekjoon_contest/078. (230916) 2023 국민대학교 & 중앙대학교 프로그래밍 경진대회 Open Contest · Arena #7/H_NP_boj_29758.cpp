// Solve 2023-09-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dp[70001][6] = { 0 };

    dp[1][1] = 1;

    for (int i = 1; i <= 264; i++) {
        for (int j = 1; j <= 4; j++) {
            if (dp[i][j] == 0) continue;

            int jj = j + 1;

            for (int ii = i * i + 1; ii <= 70000; ii++) {
                dp[ii][jj] += dp[i][j];
            }
        }
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, l;
        cin >> n >> l;

        if (l >= 6) cout << 0 << '\n';
        else cout << dp[n][l] << '\n';
    }

    return 0;
}

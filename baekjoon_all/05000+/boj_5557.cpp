// Solve 2023-08-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll dp[2][21];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x;
    cin >> x;
    dp[0][x] = 1;

    int max_iter = n - 2;
    while (max_iter > 0) {
        cin >> x;

        for (int j = 0; j <= 20; j++) {
            if (j - x >= 0) dp[1][j] += dp[0][j - x];
            if (j + x <= 20) dp[1][j] += dp[0][j + x];
        }

        for (int j = 0; j <= 20; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }

        max_iter--;
    }

    cin >> x;
    cout << dp[0][x] << '\n';

    return 0;
}

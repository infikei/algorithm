// Solve 2022-06-03
// Update 2023-07-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[2][501];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        int nrow = row % 2; // new row (0 or 1)
        int prow = 1 - nrow; // previous row (0 or 1)

        for (int col = 1; col <= row; col++) {
            cin >> dp[nrow][col];
            dp[nrow][col] += max(dp[prow][col - 1], dp[prow][col]);
        }
    }

    cout << *max_element(dp[n % 2] + 1, dp[n % 2] + (n + 1)) << '\n';

    return 0;
}

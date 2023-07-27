// Solve 2023-07-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[100000][3];

int main() {
    FASTIO;

    int test_num = 1;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
        dp[0][0] = 1000;
        dp[0][2] += dp[0][1];

        for (int i = 1; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a;
            dp[i][1] = min(min(min(dp[i][0], dp[i - 1][0]), dp[i - 1][1]), dp[i - 1][2]) + b;
            dp[i][2] = min(min(dp[i][1], dp[i - 1][1]), dp[i - 1][2]) + c;
        }

        cout << test_num << ". " << dp[n - 1][1] << '\n';

        test_num++;
    }

    return 0;
}

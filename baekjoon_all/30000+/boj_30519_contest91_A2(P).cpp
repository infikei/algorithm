// Solve 2023-11-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000007;

int main() {
    FASTIO;

    char c;
    string s;
    cin >> c >> s;

    vector<vector<int> > dp(4, vector<int>(4, 0));

    if (c == 'R') dp[0][1] = 1;
    else if (c == 'S') dp[0][2] = 1;
    else dp[0][3] = 1;

    for (int pos = 0; pos < SIZE(s); pos++) {
        vector<vector<int> > dp2 = dp;

        if (s[pos] == 'R') {
            for (int j = 1; j <= 3; j++) {
                dp[j][1] += dp2[0][j];
                dp[j][1] %= MOD;

                for (int i = 1; i <= 3; i++) {
                    if (i == 3 && j == 1) continue;
                    dp[j][1] += dp2[i][j];
                    dp[j][1] %= MOD;
                }
            }
        }
        else if (s[pos] == 'S') {
            for (int j = 1; j <= 3; j++) {
                dp[j][2] += dp2[0][j];
                dp[j][2] %= MOD;

                for (int i = 1; i <= 3; i++) {
                    if (i == 1 && j == 2) continue;
                    dp[j][2] += dp2[i][j];
                    dp[j][2] %= MOD;
                }
            }
        }
        else {
            for (int j = 1; j <= 3; j++) {
                dp[j][3] += dp2[0][j];
                dp[j][3] %= MOD;

                for (int i = 1; i <= 3; i++) {
                    if (i == 2 && j == 3) continue;
                    dp[j][3] += dp2[i][j];
                    dp[j][3] %= MOD;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            ans += dp[i][j];
            ans %= MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}

// Solve 2022-08-03
// Update 2023-07-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[1001][1001];

int main() {
    FASTIO;

    string s, s2;
    cin >> s >> s2;

    int len_s = SIZE(s), len_s2 = SIZE(s2);

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_s2; j++) {
            if (s[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[len_s][len_s2] << '\n';

    return 0;
}

// Solve 2023-07-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1000000;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int dp[3] = { 0, 1, 0 };

    if (s[0] != '0') {
        dp[2] = 1;
    }

    int i = 1, i_end = SIZE(s);

    while (i < i_end) {
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = 0;

        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            dp[2] += dp[0];
        }

        if (s[i] != '0') {
            dp[2] += dp[1];
        }

        dp[2] %= MOD;
        i++;
    }

    cout << dp[2] << '\n';

    return 0;
}

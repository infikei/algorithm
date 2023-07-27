// Solve 2023-07-26

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

    int n, m;
    cin >> n >> m;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '1') {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans << '\n';

    return 0;
}

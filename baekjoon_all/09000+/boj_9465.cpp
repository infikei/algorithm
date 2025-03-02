// Solve 2022-09-09
// Update 2025-03-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int dp[2][100000];

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dp[i][j];
            }
        }

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];

        for (int j = 2; j < n; j++) {
            dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
            dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}

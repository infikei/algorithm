// Solve 2023-07-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[41] = { 1, 1, 2 };

int main() {
    FASTIO;

    for (int i = 3; i < 41; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    int n, m;
    cin >> n >> m;

    int ans = 1, px = 0;
    for (int i = 0; i < m; i++) {
        int nx;
        cin >> nx;
        ans *= dp[nx - px - 1];
        px = nx;
    }
    ans *= dp[n - px];

    cout << ans << '\n';

    return 0;
}

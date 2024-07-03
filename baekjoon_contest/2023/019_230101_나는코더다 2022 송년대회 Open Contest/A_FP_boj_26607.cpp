// Solve 2023-01-02
// Update 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    int max_a = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        max_a = max(max_a, a[i]);
    }

    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(k + 1, vector<bool>(n * x + 1, false)));

    for (int ni = 1; ni <= n; ni++) {
        dp[ni][1][a[ni]] = true;

        for (int ki = 1; ki <= k; ki++) {
            for (int si = 1; si <= ki * max_a; si++) {
                if (dp[ni - 1][ki][si] || (si >= a[ni] && dp[ni - 1][ki - 1][si - a[ni]])) {
                    dp[ni][ki][si] = true;
                }
            }
        }
    }

    int max_sum_a = 0;
    int kx = k * x;

    for (int si = 1, si_end = k * max_a; si <= si_end; si++) {
        if (!dp[n][k][si]) continue;

        if (abs(kx - 2 * si) < abs(kx - 2 * max_sum_a)) {
            max_sum_a = si;
        }
    }

    int ans = max_sum_a * (kx - max_sum_a);

    cout << ans << '\n';

    return 0;
}

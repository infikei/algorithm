// Solve 2022-09-15
// Update 2023-07-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[1500002];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;

        int ni = i + t;

        dp[i] = max(dp[i], dp[i - 1]);

        if (ni <= n + 1) {
            dp[ni] = max(dp[ni], dp[i] + p);
        }
    }

    cout << max(dp[n], dp[n + 1]) << '\n';

    return 0;
}

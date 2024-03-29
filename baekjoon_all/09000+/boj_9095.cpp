// Solve 2023-03-23
// Update 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int dp[11] = { 0, 1, 2, 4 };

    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}

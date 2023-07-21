// Solve 2022-07-29
// Update 2023-07-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[42] = { 1, 0, 1 };

int main() {
    FASTIO;

    for (int i = 3; i < 42; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;
        cout << dp[n] << ' ' << dp[n + 1] << '\n';
    }

    return 0;
}

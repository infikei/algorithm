// Solve 2022-10-22
// Update 2023-07-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[11] = { 0, 1, 2, 4 };

string solve(int n, int k) {
    if (n == 1) {
        return "1";
    }
    else if (n == 2 && k == 2) {
        return "2";
    }
    else if (n == 3 && k == 4) {
        return "3";
    }
    else if (k <= dp[n - 1]) {
        return "1+" + solve(n - 1, k);
    }
    else if (k <= dp[n - 1] + dp[n - 2]) {
        return "2+" + solve(n - 2, k - dp[n - 1]);
    }
    else {
        return "3+" + solve(n - 3, k - dp[n - 1] - dp[n - 2]);
    }
}

int main() {
    FASTIO;

    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    int n, k;
    cin >> n >> k;

    if (k > dp[n]) {
        cout << -1 << '\n';
    }
    else {
        cout << solve(n, k) << '\n';
    }

    return 0;
}

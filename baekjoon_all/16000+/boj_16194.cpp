// Solve 2023-08-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[1001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int p;
    cin >> p;

    for (int j = 1; j <= n; j++) {
        dp[j] = dp[j - 1] + p;
    }

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        for (int j = i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i] + p);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}

// Solve 2022-07-13
// Update 2023-09-02

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

    for (int i = 1; i <= n; i++) {
        cin >> dp[i];

        int j = 1, j_end = i / 2;

        while (j <= j_end) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
            j++;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}

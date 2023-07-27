// Solve 2022-06-29
// Update 2023-07-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
    }

    int k = 2, k2 = 4;
    while (k2 <= n) {
        for (int i = k2; i <= n; i++) {
            dp[i] = min(dp[i], dp[i - k2] + 1);
        }

        k++;
        k2 = k * k;
    }

    cout << dp[n] << '\n';

    return 0;
}

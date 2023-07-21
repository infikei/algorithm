// Solve 2022-07-26
// Update 2023-07-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MAX_N = 1e6;
int dp[MAX_N + 1], parent[MAX_N + 1];

int main() {
    FASTIO;

    int n;
    cin >> n;

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        parent[i] = i - 1;

        if (i % 2 == 0) {
            int ni = i / 2;
            if (dp[ni] < dp[i]) {
                dp[i] = dp[ni];
                parent[i] = ni;
            }
        }

        if (i % 3 == 0) {
            int ni = i / 3;
            if (dp[ni] < dp[i]) {
                dp[i] = dp[ni];
                parent[i] = ni;
            }
        }

        dp[i]++;
    }

    cout << dp[n] << '\n';
    int cur = n;
    while (cur != 1) {
        cout << cur << ' ';
        cur = parent[cur];
    }
    cout << cur << '\n';

    return 0;
}

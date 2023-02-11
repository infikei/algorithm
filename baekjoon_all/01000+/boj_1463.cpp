// Solve 2022-06-03
// Update 2023-02-09

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 1e6;
int n, dp[MAX_N + 1];

int main() {
    FASTIO;

    cin >> n;

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];

        if (i % 2 == 0) {
            int ni = i / 2;
            if (dp[ni] < dp[i]) {
                dp[i] = dp[ni];
            }
        }

        if (i % 3 == 0) {
            int ni = i / 3;
            if (dp[ni] < dp[i]) {
                dp[i] = dp[ni];
            }
        }

        dp[i]++;
    }

    cout << dp[n] << '\n';

    return 0;
}
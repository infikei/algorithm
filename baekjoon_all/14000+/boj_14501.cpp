// Solve 2022-07-09
// Update 2023-03-03

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 16;
int t[MAX_N], p[MAX_N], dp[MAX_N];

int main() {
    FASTIO;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 0;
        for (int j = i + t[i]; j <= n; j++) {
            dp[i] = max(dp[i], p[i] + dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}
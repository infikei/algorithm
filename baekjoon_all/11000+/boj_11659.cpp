// Solve 2022-06-23
// Update 2023-07-20

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

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dp[i] = dp[i - 1] + x;
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << '\n';
    }

    return 0;
}

// Solve 2023-08-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool dp[51][1001];

int main() {
    FASTIO;

    int n, s, m;
    cin >> n >> s >> m;

    dp[0][s] = true;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        for (int j = 0; j <= m; j++) {
            if (!dp[i][j]) continue;

            if (j - v >= 0) dp[i + 1][j - v] = true;
            if (j + v <= m) dp[i + 1][j + v] = true;
        }
    }

    int ans = -1;
    for (int j = m; j >= 0; j--) {
        if (dp[n][j]) {
            ans = j;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}

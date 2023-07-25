// Solve 2023-07-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int coin[20], dp[10001] = { 1 } ;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }

        int m;
        cin >> m;

        for (int j = 1; j <= m; j++) {
            dp[j] = 0;
        }

        for (int i = 0; i < n; i++) {
            int c = coin[i];

            for (int j = c; j <= m; j++) {
                dp[j] += dp[j - c];
            }
        }

        cout << dp[m] << '\n';
    }

    return 0;
}

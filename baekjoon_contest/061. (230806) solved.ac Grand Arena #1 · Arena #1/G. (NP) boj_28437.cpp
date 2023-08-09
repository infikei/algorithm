// Solve 2023-08-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[100001], ans[100001];

int main() {
    FASTIO;

    dp[1] = 1;

    for (int i = 2; i <= 100000; i++) {
        dp[i]++;

        for (int j = i + i; j <= 100000; j += i) {
            dp[j] += dp[i];
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int j = x, jj = 1; j <= 100000; j += x, jj++) {
            ans[j] += dp[jj];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        cout << ans[x] << ' ';
    }
    cout << '\n';

    return 0;
}

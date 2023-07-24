// Solve 2023-07-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp[31];

int main() {
    FASTIO;

    int t, w;
    cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;

        int j = x - 1, j_end = min(w, i);

        while (j <= j_end) {
            if (j > 0) {
                dp[j] = max(dp[j - 1], dp[j]);
            }
            dp[j]++;

            j += 2;
        }
    }

    cout << *max_element(dp, dp + (w + 1)) << '\n';

    return 0;
}

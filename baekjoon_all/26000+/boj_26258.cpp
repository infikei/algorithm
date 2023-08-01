// Solve 2023-08-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int x[100000], dp[100000];

    int y_prev, y_cur;
    cin >> x[0] >> y_prev;

    for (int i = 1; i < n; i++) {
        cin >> x[i] >> y_cur;

        if (y_prev < y_cur) {
            dp[i] = 1;
        }
        else if (y_prev > y_cur) {
            dp[i] = -1;
        }
        else {
            dp[i] = 0;
        }

        y_prev = y_cur;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        double k;
        cin >> k;

        int pos = upper_bound(x, x + n, k) - x;
        cout << dp[pos] << '\n';
    }

    return 0;
}

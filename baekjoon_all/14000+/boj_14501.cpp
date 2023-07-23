// Solve 2022-07-09
// Update 2023-07-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dp_p[16], dp_t[16];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;

        dp_t[i] = i + t;
        if (dp_t[i] > n + 1) continue;

        for (int j = 1; j < i; j++) {
            if (dp_t[j] <= i) {
                dp_p[i] = max(dp_p[i], dp_p[j]);
            }
        }

        dp_p[i] += p;
    }

    cout << *max_element(dp_p + 1, dp_p + (n + 1)) << '\n';

    return 0;
}

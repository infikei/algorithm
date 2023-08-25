// Solve 2022-08-20
// Update 2023-08-25

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

    int s[10], b[10];

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    int ans = abs(s[0] - b[0]);

    for (int i = 1, ie = (1 << n); i < ie; i++) {
        int s_prod = 1, b_sum = 0;

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                s_prod *= s[j];
                b_sum += b[j];
            }
        }

        ans = min(ans, abs(s_prod - b_sum));
    }

    cout << ans << '\n';

    return 0;
}

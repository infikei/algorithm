// Solve 2023-04-24
// Update 2023-10-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;

    int ans = 0;

    for (int k = 1; k <= n; k++) {
        int k2 = k;

        while (k2 > 0) {
            if (k2 % 10 == d) {
                ans++;
            }

            k2 /= 10;
        }
    }

    cout << ans << '\n';

    return 0;
}

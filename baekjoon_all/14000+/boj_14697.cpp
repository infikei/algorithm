// Solve 2023-01-15
// Update 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int ans = 0;

    for (int i = 0; i <= n; i += c) {
        for (int j = 0, je = n - i; j <= je; j += b) {
            if ((je - j) % a == 0) {
                ans = 1;
                break;
            }
        }

        if (ans) break;
    }

    cout << ans << '\n';

    return 0;
}

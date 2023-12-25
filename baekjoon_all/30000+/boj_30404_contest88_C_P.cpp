// Solve 2023-10-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int ans = 0, x0 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > x0) {
            ans++;
            x0 = x + k;
        }
    }

    cout << ans << '\n';

    return 0;
}

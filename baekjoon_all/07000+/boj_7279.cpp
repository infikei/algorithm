// Solve 2023-12-05

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

    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        cur += a - b;
        ans = max(ans, cur);
    }

    ans = max(ans - k, 0);

    cout << ans << '\n';

    return 0;
}

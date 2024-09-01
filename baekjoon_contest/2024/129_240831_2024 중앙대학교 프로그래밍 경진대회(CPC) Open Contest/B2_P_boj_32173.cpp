// Solve 2024-08-31

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

    ll ans = 0;
    ll s = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ans = max(ans, x - s);
        s += x;
    }

    cout << ans << '\n';

    return 0;
}

// Solve 2023-09-25
// Update 2023-12-25

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

    int ans = (n - 1) * 2;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        ans += a - 2;
    }

    ans *= 180;

    cout << ans << '\n';

    return 0;
}

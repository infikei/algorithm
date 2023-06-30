// Solve 2023-06-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, x;
    cin >> n >> x;

    int a0, a1;
    cin >> a0 >> a1;
    int ans = a0 + a1;
    for (int i = 2; i < n; i++) {
        a0 = a1;
        cin >> a1;
        ans = min(ans, a0 + a1);
    }

    ans *= x;
    cout << ans << '\n';

    return 0;
}

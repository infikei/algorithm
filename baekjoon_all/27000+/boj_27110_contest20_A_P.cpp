// Solve 2023-01-08
// Update 2023-08-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;

        ans += min(n, a);
    }

    cout << ans << '\n';

    return 0;
}

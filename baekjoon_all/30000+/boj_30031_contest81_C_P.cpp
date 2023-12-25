// Solve 2023-09-17
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

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;

        if (w == 136) ans += 1000;
        else if (w == 142) ans += 5000;
        else if (w == 148) ans += 10000;
        else if (w == 154) ans += 50000;
    }

    cout << ans << '\n';

    return 0;
}

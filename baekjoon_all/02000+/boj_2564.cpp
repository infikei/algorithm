// Solve 2024-01-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int w, h, n;
    cin >> w >> h >> n;

    int position[101];
    int w_plus_h = w + h;

    for (int i = 0; i <= n; i++) {
        int direction, dist;
        cin >> direction >> dist;

        if (direction == 1) {
            position[i] = dist;
        }
        else if (direction == 2) {
            position[i] = w * 2 + h - dist;
        }
        else if (direction == 3) {
            position[i] = w_plus_h * 2 - dist;
        }
        else {
            position[i] = w + dist;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cur = abs(position[i] - position[n]);
        cur = min(cur, w_plus_h * 2 - cur);
        ans += cur;
    }

    cout << ans << '\n';

    return 0;
}

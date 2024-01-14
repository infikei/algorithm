// Solve 2024-01-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<string> gears(5);
    int center[5] = { 0 };

    for (int x = 1; x <= 4; x++) {
        cin >> gears[x];
    }

    int k;
    cin >> k;

    for (int ki = 0; ki < k; ki++) {
        int direction[5] = { 0 };

        int x;
        cin >> x;
        cin >> direction[x];

        for (int y = x + 1; y <= 4; y++) {
            int right = (center[y - 1] + 2) % 8;
            int left = (center[y] + 6) % 8;

            if (gears[y - 1][right] != gears[y][left]) {
                direction[y] = -direction[y - 1];
            }
            else {
                break;
            }
        }

        for (int y = x - 1; y >= 1; y--) {
            int right = (center[y] + 2) % 8;
            int left = (center[y + 1] + 6) % 8;

            if (gears[y][right] != gears[y + 1][left]) {
                direction[y] = -direction[y + 1];
            }
            else {
                break;
            }
        }

        for (int y = 1; y <= 4; y++) {
            center[y] = (center[y] - direction[y] + 8) % 8;
        }
    }

    int ans = 0;

    for (int x = 1; x <= 4; x++) {
        ans += (gears[x][center[x]] - '0') * (1 << (x - 1));
    }

    cout << ans << '\n';

    return 0;
}

// Solve 2023-08-31
// Update 2023-12-20

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

    int room[1000][1000];
    int sx = 0, sy = 0; // 성규의 좌표
    int px = 0, py = 0; // 교수님의 좌표

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> room[i][j];

            if (room[i][j] == 2) {
                sx = i; sy = j;
            }
            else if (room[i][j] == 5) {
                px = i; py = j;
            }
        }
    }

    int dx = sx - px;
    int dy = sy - py;
    int ans = 0;

    if (dx * dx + dy * dy >= 25) {
        int cnt = 0;

        for (int i = min(sx, px), ie = max(sx, px); i <= ie; i++) {
            for (int j = min(sy, py), je = max(sy, py); j <= je; j++) {
                if (room[i][j] == 1) {
                    if (++cnt >= 3) {
                        ans = 1;
                        break;
                    }
                }
            }

            if (ans == 1) break;
        }
    }

    cout << ans << '\n';

    return 0;
}

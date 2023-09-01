// Solve 2023-09-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int graph[2000][2000];

int main() {
    FASTIO;

    int x[4], y[4];

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = x[0] + 1000, ie = x[1] + 1000; i < ie; i++) {
        for (int j = y[0] + 1000, je = y[1] + 1000; j < je; j++) {
            graph[i][j] = 1;
        }
    }

    for (int i = x[2] + 1000, ie = x[3] + 1000; i < ie; i++) {
        for (int j = y[2] + 1000, je = y[3] + 1000; j < je; j++) {
            graph[i][j] = 0;
        }
    }

    int xs = 1999, xe = 0, ys = 1999, ye = 0;

    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (graph[i][j] == 1) {
                xs = min(xs, i);
                xe = max(xe, i);
                ys = min(ys, j);
                ye = max(ye, j);
            }
        }
    }

    int ans = max(0, xe - xs + 1) * max(0, ye - ys + 1);

    cout << ans << '\n';

    return 0;
}

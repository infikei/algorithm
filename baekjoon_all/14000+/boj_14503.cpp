// Solve 2023-04-13

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int graph[50][50];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int ans = 0;
    while (true) {
        if (graph[r][c] == 0) {
            graph[r][c] = 2;
            ans++;
        }

        bool go = false;
        for (int i = 0; i < 4; i++) {
            d--;
            if (d == -1) d = 3;
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (graph[nr][nc] == 0) {
                r = nr;
                c = nc;
                go = true;
                break;
            }
        }
        if (go) continue;

        r -= dr[d];
        c -= dc[d];
        if (graph[r][c] == 1) {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}

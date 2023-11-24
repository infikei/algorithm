// Solve 2023-11-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Pair{
    int r, c;
    Pair(int r, int c) : r(r), c(c) {}
};

int main() {
    FASTIO;

    int dr[4] = { 0, 0, -1, 1 };
    int dc[4] = { -1, 1, 0, 0 };

    int n, m, k;
    cin >> n >> m >> k;

    int room[500][500];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> room[r][c];
        }
    }

    bool visited[500][500] = { false };
    int ans = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (visited[r][c]) continue;

            visited[r][c] = true;
            ans++;
            queue<Pair> bfs_que;
            bfs_que.emplace(r, c);

            while (!bfs_que.empty()) {
                Pair p = bfs_que.front();
                bfs_que.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = p.r + dr[d];
                    int nc = p.c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (visited[nr][nc]) continue;
                    if (abs(room[p.r][p.c] - room[nr][nc]) > k) continue;

                    visited[nr][nc] = true;
                    bfs_que.emplace(nr, nc);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

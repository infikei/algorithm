// Solve 2023-09-17
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Oksusu{
    int row, col, value;

    Oksusu(int r = 0, int c = 0, int v = 0) : row(r), col(c), value(v) {}

    bool operator<(const Oksusu &rhs) const {
        return value < rhs.value;
    }
};

int main() {
    FASTIO;

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    int n, m;
    cin >> n >> m;

    vector<vector<int>> farm(n, vector<int>(m, 0));
    priority_queue<Oksusu> oksusu_maxtop;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int v;
            cin >> v;

            if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                oksusu_maxtop.emplace(r, c, v);
            }
            else {
                farm[r][c] = v;
            }
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        Oksusu top = oksusu_maxtop.top();
        oksusu_maxtop.pop();

        cout << top.row + 1 << ' ' << top.col + 1 << '\n';

        for (int d = 0; d < 4; d++) {
            int nr = top.row + dr[d];
            int nc = top.col + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (farm[nr][nc] == 0) continue;

            oksusu_maxtop.emplace(nr, nc, farm[nr][nc]);
            farm[nr][nc] = 0;
        }
    }

    return 0;
}

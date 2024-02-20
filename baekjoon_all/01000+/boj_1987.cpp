// Solve 2023-02-19
// Update 2024-02-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
string board[20];
int max_depth;

void dfs(int x, int y, int depth, int selected) {
    max_depth = max(max_depth, depth);

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && (selected & 1 << (board[nx][ny] - 'A')) == 0) {
            dfs(nx, ny, depth + 1, selected | 1 << (board[nx][ny] - 'A'));
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    dfs(0, 0, 1, 1 << (board[0][0] - 'A'));
    cout << max_depth << '\n';

    return 0;
}

// Solve 2025-07-13

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int min_dist[2][3000][3000];

void bfs(int idx, int start_x, int start_y, int n, int m, vector<string>& board) {
    queue<pii> que;
    que.emplace(start_x, start_y);
    min_dist[idx][start_x][start_y] = 0;
    int cur_dist = 0;

    while (!que.empty()) {
        cur_dist++;
        int iter = size(que);

        while (iter-- > 0) {
            pii cur = que.front();
            que.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] == '#') continue;
                if (min_dist[idx][nx][ny] != INF) continue;

                min_dist[idx][nx][ny] = cur_dist;
                que.emplace(nx, ny);
            }
        }
    }
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> board(n);

    for (string& row : board) {
        cin >> row;
    }

    pii s, j;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 'S') {
                s = {x, y};
            }
            else if (board[x][y] == 'J') {
                j = {x, y};
            }
        }
    }

    memset(min_dist, 0x3f, sizeof min_dist);
    bfs(0, j.first, j.second, n, m, board);
    bfs(1, s.first, s.second, n, m, board);
    int ans = INF;

    if (min_dist[0][s.first][s.second] != INF) {
        ans = 2 * min_dist[0][s.first][s.second];
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 'T' && min_dist[0][x][y] != INF && min_dist[1][x][y] != INF) {
                ans = min(ans, min_dist[0][x][y] * 2 + min_dist[1][x][y]);
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}

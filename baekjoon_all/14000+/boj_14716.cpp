// Solve 2025-06-25

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

int m, n;
int board[250][250];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int x, int y) {
    queue<pii> bfs_que;
    bfs_que.emplace(x, y);
    board[x][y] = 0;

    while (!bfs_que.empty()) {
        pii cur = bfs_que.front();
        bfs_que.pop();

        for (int d = 0; d < 8; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 0) continue;

            bfs_que.emplace(nx, ny);
            board[nx][ny] = 0;
        }
    }
}

void input() {
    cin >> m >> n;

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }
}

void pro() {
    int cnt = 0;

    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == 1) {
                cnt++;
                bfs(x, y);
            }
        }
    }

    cout << cnt << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}

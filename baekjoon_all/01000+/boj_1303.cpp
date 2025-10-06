// Solve 2025-10-06

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

int n, m;
string board[100];
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int r, int c) {
    queue<pii> que;
    que.emplace(r, c);
    visited[r][c] = true;
    int ret = 1;

    while (!que.empty()) {
        pii cur = que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || board[nx][ny] != board[x][y]) continue;

            visited[nx][ny] = true;
            que.emplace(nx, ny);
            ret++;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> m >> n; // 세로 크기를 n으로, 가로 크기를 m으로 재정의

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    int white = 0;
    int blue = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (visited[x][y]) continue;

            int cnt = bfs(x, y);

            if (board[x][y] == 'W') {
                white += cnt * cnt;
            }
            else {
                blue += cnt * cnt;
            }
        }
    }

    cout << white << ' ' << blue << '\n';
    return 0;
}

// Solve 2025-03-28

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int board[3][3];
bool visited[3][3];
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    queue<pii> bfs_que;
    bfs_que.emplace(0, 0);
    visited[0][0] = true;
    bool can_reach = false;

    while (!bfs_que.empty()) {
        pii cur = bfs_que.front();
        bfs_que.pop();

        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 2; d++) {
            int nx = x + dx[d] * board[x][y];
            int ny = y + dy[d] * board[x][y];

            if (nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if (nx == n - 1 && ny == n - 1) {
                can_reach = true;
                continue;
            }

            bfs_que.emplace(nx, ny);
        }
    }

    cout << (can_reach ? "HaruHaru" : "Hing") << '\n';

    return 0;
}

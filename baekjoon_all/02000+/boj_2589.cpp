// Solve 2024-12-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool visited[50][50];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> board(n);

    for (string &row : board) {
        cin >> row;
    }

    int max_dist = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] != 'L') continue;

            for (int bx = 0; bx < n; bx++) {
                for (int by = 0; by < m; by++) {
                    visited[bx][by] = false;
                }
            }

            queue<pii> bfs_que;
            bfs_que.emplace(x, y);
            visited[x][y] = true;
            int dist = -1;

            while (!bfs_que.empty()) {
                int iter = size(bfs_que);
                dist++;

                while (iter-- > 0) {
                    pii cur = bfs_que.front();
                    bfs_que.pop();
                    int cx = cur.first;
                    int cy = cur.second;

                    for (int d = 0; d < 4; d++) {
                        int nx = cx + dx[d];
                        int ny = cy + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                        if (!visited[nx][ny] && board[nx][ny] == 'L') {
                            visited[nx][ny] = true;
                            bfs_que.emplace(nx, ny);
                        }
                    }
                }
            }

            max_dist = max(max_dist, dist);
        }
    }

    println(max_dist);

    return 0;
}

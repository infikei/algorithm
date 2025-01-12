// Solve 2025-01-08

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
int board[100][100];
bool searched[100][100];
bool visited[100][100];

void init_visited(int n) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            visited[x][y] = false;
        }
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];
        }
    }

    int min_bridge = 1000;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[x][y] == 0 || searched[x][y]) continue;

            queue<pii> bfs_que, bfs_que2;
            init_visited(n);

            bfs_que2.emplace(x, y);
            searched[x][y] = true;
            visited[x][y] = true;

            while (!bfs_que2.empty()) {
                pii cur = bfs_que2.front();
                bfs_que2.pop();
                bfs_que.push(cur);

                for (int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny] || board[nx][ny] == 0) continue;

                    bfs_que2.emplace(nx, ny);
                    searched[nx][ny] = true;
                    visited[nx][ny] = true;
                }
            }

            int bridge = 0;

            while (!bfs_que.empty()) {
                int iter = size(bfs_que);
                bool found_bridge = false;

                while (iter-- > 0) {
                    pii cur = bfs_que.front();
                    bfs_que.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (visited[nx][ny]) continue;

                        visited[nx][ny] = true;

                        if (board[nx][ny] == 1) {
                            found_bridge = true;
                        }
                        else {
                            bfs_que.emplace(nx, ny);
                        }
                    }
                }

                if (found_bridge) {
                    min_bridge = min(min_bridge, bridge);
                    break;
                }

                bridge++;
            }
        }
    }

    println(min_bridge);

    return 0;
}

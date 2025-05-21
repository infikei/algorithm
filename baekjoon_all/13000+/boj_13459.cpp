// Solve 2025-02-15
// Update 2025-05-21

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

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m;
vector<string> board;
bool visited[10][10][10][10];

struct Balls{
    int rx, ry, bx, by;

    Balls() {
    }

    Balls(int rx, int ry, int bx, int by) : rx(rx), ry(ry), bx(bx), by(by) {
    }
};

int move(int x, int y, int d) {
    int moved = 1;
    int nx = x + dx[d];
    int ny = y + dy[d];

    while (board[nx][ny] == '.') {
        moved++;
        nx += dx[d];
        ny += dy[d];
    }

    if (board[nx][ny] == 'O') {
        return moved;
    }

    return moved - 1;
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        string s;
        cin >> s;
        board.push_back(s);
    }

    Balls balls;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] == 'R') {
                balls.rx = x;
                balls.ry = y;
                board[x][y] = '.';
            }
            else if (board[x][y] == 'B') {
                balls.bx = x;
                balls.by = y;
                board[x][y] = '.';
            }
        }
    }

    queue<Balls> bfs_que;
    bfs_que.push(balls);
    visited[balls.rx][balls.ry][balls.bx][balls.by] = true;
    int ans = -1;

    for (int depth = 1; depth <= 10; depth++) {
        int bfs_iter = size(bfs_que);

        while (bfs_iter-- > 0) {
            Balls cur = bfs_que.front();
            bfs_que.pop();

            for (int d = 0; d < 4; d++) {
                int red_moved = move(cur.rx, cur.ry, d);
                int blue_moved = move(cur.bx, cur.by, d);

                Balls nxt = cur;
                nxt.rx += dx[d] * red_moved;
                nxt.ry += dy[d] * red_moved;
                nxt.bx += dx[d] * blue_moved;
                nxt.by += dy[d] * blue_moved;

                // 파란 구슬이 구멍에 들어가면 더 이상 탐색하지 않는다.
                if (board[nxt.bx][nxt.by] == 'O') {
                    continue;
                }

                // 빨간 구슬과 파란 구슬은 같은 칸에 위치할 수 없으므로 더 먼 거리를 이동한 구슬을 한 칸 뒤로 이동시킨다.
                if (nxt.rx == nxt.bx && nxt.ry == nxt.by) {
                    if (red_moved > blue_moved) {
                        nxt.rx -= dx[d];
                        nxt.ry -= dy[d];
                    }
                    else {
                        nxt.bx -= dx[d];
                        nxt.by -= dy[d];
                    }
                }

                // 빨간 구슬이 구멍에 들어가면 그때의 횟수를 답에 저장하고 탐색을 종료한다.
                if (board[nxt.rx][nxt.ry] == 'O') {
                    ans = depth;
                    break;
                }

                // 이미 탐색이 진행된 경우라면 중복해서 탐색하지 않는다.
                if (visited[nxt.rx][nxt.ry][nxt.bx][nxt.by]) {
                    continue;
                }

                bfs_que.push(nxt);
                visited[nxt.rx][nxt.ry][nxt.bx][nxt.by] = true;
            }

            if (ans != -1) break;
        }

        if (ans != -1) break;
    }

    if (ans == -1) {
        cout << 0 << '\n';
    }
    else {
        cout << 1 << '\n';
    }

    return 0;
}

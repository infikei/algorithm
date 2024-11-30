// Solve 2024-01-03
// Update 2024-01-14

#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int board[15][15];
int min_time[15][15];

struct Node{
    int x, y, t;

    Node(int x = 0, int y = 0, int t = 0) : x(x), y(y), t(t) {}

    bool operator<(const Node &rhs) const {
        if (t != rhs.t) return t > rhs.t;
        if (x != rhs.x) return x > rhs.x;
        return y > rhs.y;
    }
};

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                min_time[i][j] = INF;
            }
        }

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        priority_queue<Node> pq_mintop;
        pq_mintop.emplace(sx, sy, 0);
        min_time[sx][sy] = 0;

        while (!pq_mintop.empty()) {
            Node cur = pq_mintop.top();
            pq_mintop.pop();

            if (cur.x == ex && cur.y == ey) break;
            if (cur.t > min_time[cur.x][cur.y]) continue;

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if (board[nx][ny] == 0) {
                    int nt = cur.t + 1;

                    if (nt < min_time[nx][ny]) {
                        min_time[nx][ny] = nt;
                        pq_mintop.emplace(nx, ny, nt);
                    }
                }
                else if (board[nx][ny] == 2) {
                    int nt = cur.t + 1;
                    nt = (nt + 2) / 3 * 3;

                    if (nt < min_time[nx][ny]) {
                        min_time[nx][ny] = nt;
                        pq_mintop.emplace(nx, ny, nt);
                    }
                }
            }
        }

        cout << '#' << test_case << ' ' << (min_time[ex][ey] == INF ? -1 : min_time[ex][ey]) << '\n';
    }

    return 0;
}

// Solve 2024-01-14

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node{
    int x, y, d;

    Node(int x, int y, int d) : x(x), y(y), d(d) {}

    bool operator<(const Node &rhs) const {
        if (d != rhs.d) return d > rhs.d;
        if (x != rhs.x) return x > rhs.x;
        return y > rhs.y;
    }
};

const int INF = 1e9;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int board[100][100];
int dist[100][100];

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < n; j++) {
                board[i][j] = s[j] - '0';
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = INF;
            }
        }

        dist[0][0] = 0;
        priority_queue<Node> pq_mintop;
        pq_mintop.emplace(0, 0, 0);

        while (!pq_mintop.empty()) {
            Node cur = pq_mintop.top();
            pq_mintop.pop();

            if (cur.x == n - 1 && cur.y == n - 1) break;
            if (cur.d > dist[cur.x][cur.y]) continue;

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int nd = cur.d + board[nx][ny];

                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq_mintop.emplace(nx, ny, nd);
                }
            }
        }

        cout << '#' << ti << ' ' << dist[n - 1][n - 1] << '\n';
    }

    return 0;
}

// Solve 2026-05-18

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

struct Node{
    int x;
    int y;
    int dist;
    int sun;

    Node(int x, int y, int dist, int sun) : x(x), y(y), dist(dist), sun(sun) {
    }

    bool operator<(const Node& rhs) const {
        if (dist != rhs.dist) {
            return dist > rhs.dist;
        }

        return sun > rhs.sun;
    }
};

int board[100][100];
int memo[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FASTIO;

    int n, t;
    cin >> n >> t;
    int sx = 0;
    int sy = 0;
    int ex = 0;
    int ey = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> board[x][y];

            if (board[x][y] < 0) {
                if (board[x][y] == -1) {
                    sx = x;
                    sy = y;
                }
                else {
                    ex = x;
                    ey = y;
                }
            }
        }
    }

    memset(memo, 0x3f, sizeof(memo));
    priority_queue<Node> pq;
    memo[sx][sy] = 0;
    pq.emplace(sx, sy, 0, 0);

    for (int ti = 1; ti <= t; ti++) {
        int iter = size(pq);

        while (iter-- > 0) {
            auto [x, y, dist, sun] = pq.top();
            pq.pop();

            if (sun > memo[x][y]) continue;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (board[nx][ny] == 0) continue;

                int nsun = sun + max(0, board[nx][ny]);

                if (nsun < memo[nx][ny]) {
                    memo[nx][ny] = nsun;
                    pq.emplace(nx, ny, dist + 1, nsun);
                }
            }
        }
    }

    cout << (memo[ex][ey] == INF ? -1 : memo[ex][ey]) << '\n';
    return 0;
}

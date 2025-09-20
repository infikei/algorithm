// Solve 2025-09-18

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

struct Position{
    int x, y, d, cnt;

    Position(int x, int y, int d, int cnt) : x(x), y(y), d(d), cnt(cnt) {
    }

    bool operator<(const Position& rhs) const {
        return cnt < rhs.cnt;
    }

    bool operator>(const Position& rhs) const {
        return rhs < *this;
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt_rotate[100][100][4];

int main() {
    FASTIO;

    int h, w;
    cin >> w >> h;
    vector<string> board(h);
    Position start_node(-1, -1, -1, 0);
    Position end_node(-1, -1, -1, 0);

    for (int x = 0; x < h; x++) {
        cin >> board[x];

        for (int y = 0; y < w; y++) {
            if (board[x][y] == 'C') {
                if (start_node.x == -1) {
                    start_node = {x, y, -1, 0};
                }
                else {
                    end_node = {x, y, -1, 0};
                }
            }
        }
    }

    priority_queue<Position, vector<Position>, greater<Position>> pq_mintop;
    memset(cnt_rotate, 0x3f, sizeof cnt_rotate);

    for (int d = 0; d < 4; d++) {
        pq_mintop.emplace(start_node.x, start_node.y, d, 0);
        cnt_rotate[start_node.x][start_node.y][d] = 0;
    }

    while (!pq_mintop.empty()) {
        Position cur = pq_mintop.top();
        pq_mintop.pop();

        if (cur.cnt > cnt_rotate[cur.x][cur.y][cur.d]) continue;

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == '*') continue;

            int n_cnt_rotate = cur.cnt + (d == cur.d ? 0 : 1);

            if (n_cnt_rotate < cnt_rotate[nx][ny][d]) {
                cnt_rotate[nx][ny][d] = n_cnt_rotate;
                pq_mintop.emplace(nx, ny, d, n_cnt_rotate);
            }
        }
    }

    int ans = INF;

    for (int d = 0; d < 4; d++) {
        ans = min(ans, cnt_rotate[end_node.x][end_node.y][d]);
    }

    cout << ans << '\n';
    return 0;
}

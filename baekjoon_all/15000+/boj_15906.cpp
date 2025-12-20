// Solve 2025-12-16

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
    int x, y, mod, dist;

    Node(int x, int y, int mod, int dist) : x(x), y(y), mod(mod), dist(dist) {
    }
};

string board[500];
vector<int> row_warp[500];
vector<int> col_warp[500];
int memo[500][500][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    FASTIO;

    int n, t, r, c;
    cin >> n >> t >> r >> c;
    r--;
    c--;

    for (int x = 0; x < n; x++) {
        cin >> board[x];

        for (int y = 0; y < n; y++) {
            if (board[x][y] == '#') {
                row_warp[x].push_back(y);
                col_warp[y].push_back(x);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sort(row_warp[i].begin(), row_warp[i].end());
        sort(col_warp[i].begin(), col_warp[i].end());
    }

    auto cmp = [](Node& o1, Node& o2) {
        return o1.dist > o2.dist;
    };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    memset(memo, INF, sizeof memo);
    memo[0][0][0] = 0;
    pq.emplace(0, 0, 0, 0);

    while (!pq.empty()) {
        auto [x, y, mod, dist] = pq.top();
        pq.pop();

        if (dist > memo[x][y][mod]) continue;
        if (x == r && y == c) break;

        if (mod == 0) {
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist + 1 < memo[nx][ny][0]) {
                    memo[nx][ny][0] = dist + 1;
                    pq.emplace(nx, ny, 0, dist + 1);
                }
            }

            if (dist + t < memo[x][y][1]) {
                memo[x][y][1] = dist + t;
                pq.emplace(x, y, 1, dist + t);
            }
        }
        else {
            auto it = upper_bound(row_warp[x].begin(), row_warp[x].end(), y);

            if (it != row_warp[x].end()) {
                int ny = *it;

                if (dist + 1 < memo[x][ny][1]) {
                    memo[x][ny][1] = dist + 1;
                    pq.emplace(x, ny, 1, dist + 1);
                }
            }

            it = lower_bound(row_warp[x].begin(), row_warp[x].end(), y);

            if (it != row_warp[x].begin()) {
                it--;
                int ny = *it;

                if (dist + 1 < memo[x][ny][1]) {
                    memo[x][ny][1] = dist + 1;
                    pq.emplace(x, ny, 1, dist + 1);
                }
            }

            it = upper_bound(col_warp[y].begin(), col_warp[y].end(), x);

            if (it != col_warp[y].end()) {
                int nx = *it;

                if (dist + 1 < memo[nx][y][1]) {
                    memo[nx][y][1] = dist + 1;
                    pq.emplace(nx, y, 1, dist + 1);
                }
            }

            it = lower_bound(col_warp[y].begin(), col_warp[y].end(), x);

            if (it != col_warp[y].begin()) {
                it--;
                int nx = *it;

                if (dist + 1 < memo[nx][y][1]) {
                    memo[nx][y][1] = dist + 1;
                    pq.emplace(nx, y, 1, dist + 1);
                }
            }

            if (dist < memo[x][y][0]) {
                memo[x][y][0] = dist;
                pq.emplace(x, y, 0, dist);
            }
        }
    }

    cout << min(memo[r][c][0], memo[r][c][1]) << '\n';
    return 0;
}

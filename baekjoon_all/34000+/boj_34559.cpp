// Solve 2025-10-17

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

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int n, m;
int board[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int r, int c) {
    queue<Point> que;
    vector<Point> vec;
    que.emplace(r, c);
    vec.emplace_back(r, c);
    visited[r][c] = true;
    bool can_reach_border = false;

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (visited[nx][ny] || board[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            que.emplace(nx, ny);
            vec.emplace_back(nx, ny);

            if (nx == 1 || nx == n || ny == 1 || ny == m) {
                can_reach_border = true;
            }
        }
    }

    if (!can_reach_border) {
        for (Point& p : vec) {
            board[p.x][p.y] = 1;
        }
    }
}

void change_to_prefix_sum() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            board[x][y] += board[x][y - 1] + board[x - 1][y] - board[x - 1][y - 1];
        }
    }
}

int get_building_cnt(int r1, int c1, int r2, int c2) {
    return board[r2][c2] - board[r2][c1 - 1] - board[r1 - 1][c2] + board[r1 - 1][c1 - 1];
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            char c;
            cin >> c;
            board[x][y] = c - '0';
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (!visited[x][y] && board[x][y] == 0) {
                bfs(x, y);
            }
        }
    }

    change_to_prefix_sum();

    int q;
    cin >> q;

    while (q-- > 0) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int building_cnt = get_building_cnt(r1, c1, r2, c2);

        if (building_cnt == 0) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No " << building_cnt << '\n';
        }
    }

    return 0;
}

// Solve 2025-10-19

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

    bool operator<(const Point& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

int n, m;
string board[100];
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int throw_stick(int x, int th) {
    int y = (th % 2 == 0 ? 0 : m - 1);
    int d = (th % 2 == 0 ? 1 : -1);

    while (y >= 0 && y < m && board[x][y] == '.') {
        y += d;
    }

    return y;
}

bool drop_separated_cluster(int x, int y) {
    memset(visited, false, sizeof visited);
    vector<Point> cluster;
    queue<Point> que;
    cluster.emplace_back(x, y);
    que.emplace(x, y);
    visited[x][y] = true;

    while (!que.empty()) {
        Point cur = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || board[nx][ny] == '.') continue;

            visited[nx][ny] = true;
            cluster.emplace_back(nx, ny);
            que.emplace(nx, ny);

            if (nx == 0) {
                return false;
            }
        }
    }

    int mn = INF;

    for (Point& p : cluster) {
        // cout << p.x << ' ' << p.y << '\n';
        int nx = p.x - 1;

        while (nx >= 0 && board[nx][p.y] == '.') {
            nx--;
        }

        if (nx < 0 || !visited[nx][p.y]) {
            mn = min(mn, p.x - nx - 1);
        }
    }

    // cout << mn << '\n';
    sort(cluster.begin(), cluster.end());

    for (Point& p : cluster) {
        board[p.x][p.y] = '.';
        board[p.x - mn][p.y] = 'x';
    }

    return true;
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int x = n - 1; x >= 0; x--) {
        cin >> board[x];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        int y = throw_stick(x, i);
        // cout << x << ' ' << y << '\n';

        if (y < 0 || y >= m) continue;

        board[x][y] = '.';
        // for (int x = n - 1; x >= 0; x--) {
        //     cout << board[x] << '\n';
        // }
        // cout << '\n';

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '.') continue;

            if (drop_separated_cluster(nx, ny)) {
                break;
            }
        }

        // for (int x = n - 1; x >= 0; x--) {
        //     cout << board[x] << '\n';
        // }
        // cout << '\n';
    }

    for (int x = n - 1; x >= 0; x--) {
        cout << board[x] << '\n';
    }

    return 0;
}

// Solve 2025-09-11

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

int adj[502][502][4];
int min_dist[502][502];
int max_turn[502][502];
int d_from[502][502][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point{
    int x, y, dist, turn;

    Point(int x, int y, int dist, int turn) : x(x), y(y), dist(dist), turn(turn) {
    }

    bool operator<(const Point& rhs) const {
        if (dist != rhs.dist) {
            return dist < rhs.dist;
        }

        return turn > rhs.turn;
    }

    bool operator>(const Point& rhs) const {
        return rhs < *this;
    }

    bool operator==(const Point &rhs) const {
        return x == rhs.x && y == rhs.y && dist == rhs.dist && turn == rhs.turn;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 1; y < n; y++) {
            int d;
            cin >> d;
            adj[x][y - 1][0] = d;
            adj[x][y][2] = d;
        }

        if (x == n - 1) break;

        for (int y = 0; y < n; y++) {
            int d;
            cin >> d;
            adj[x][y][1] = d;
            adj[x + 1][y][3] = d;
        }
    }

    memset(min_dist, 0x3f, sizeof min_dist);
    priority_queue<Point, vector<Point>, greater<Point>> pq_mintop;
    min_dist[0][0] = 0;
    pq_mintop.emplace(0, 0, 0, 0);

    while (!pq_mintop.empty()) {
        Point cur = pq_mintop.top();
        pq_mintop.pop();
        Point curcur(cur.x, cur.y, min_dist[cur.x][cur.y], max_turn[cur.x][cur.y]);

        if (cur > curcur) continue;

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int n_dist = cur.dist + adj[cur.x][cur.y][d];
            int n_turn = cur.turn + d_from[cur.x][cur.y][(d & 1) ^ 1];
            Point nxt(nx, ny, n_dist, n_turn);
            Point nxtnxt(nx, ny, min_dist[nx][ny], max_turn[nx][ny]);

            if (nxt < nxtnxt) {
                min_dist[nx][ny] = n_dist;
                max_turn[nx][ny] = n_turn;
                d_from[nx][ny][0] = 0;
                d_from[nx][ny][1] = 0;
                d_from[nx][ny][d & 1] = 1;
                pq_mintop.emplace(nx, ny, n_dist, n_turn);
            }
            else if (nxt == nxtnxt) {
                d_from[nx][ny][d & 1] = 1;
            }
        }
    }

    cout << min_dist[n - 1][n - 1] << ' ' << max_turn[n - 1][n - 1] << '\n';

    return 0;
}

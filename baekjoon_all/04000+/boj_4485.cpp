// Solve 2023-11-24
// Update 2024-03-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

struct Point{
    int x, y, cost;

    Point(int x, int y, int cost) : x(x), y(y), cost(cost) {}

    bool operator<(const Point &rhs) const {
        if (cost != rhs.cost) cost < rhs.cost;
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }

    bool operator>(const Point &rhs) const {
        return !(*this < rhs);
    }
};

int main() {
    FASTIO;

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int ti = 0;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<vector<int>> board(n, vector<int>(n, 0));

        for (vector<int> &row : board) {
            for (int &col : row) {
                cin >> col;
            }
        }

        vector<vector<int>> min_dist(n, vector<int>(n, INF));
        priority_queue<Point, vector<Point>, greater<Point> > pq_mintop;
        min_dist[0][0] = board[0][0];
        pq_mintop.emplace(0, 0, board[0][0]);

        while (!pq_mintop.empty()) {
            Point cur = pq_mintop.top();
            pq_mintop.pop();

            if (min_dist[cur.x][cur.y] < cur.cost) continue;
            if (cur.x == n - 1 && cur.y == n - 1) break;

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int ncost = cur.cost + board[nx][ny];

                if (min_dist[nx][ny] > ncost) {
                    min_dist[nx][ny] = ncost;
                    pq_mintop.emplace(nx, ny, ncost);
                }
            }
        }

        cout << "Problem " << ++ti << ": " << min_dist[n - 1][n - 1] << '\n';
    }

    return 0;
}

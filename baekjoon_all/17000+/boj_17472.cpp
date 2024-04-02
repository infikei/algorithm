// Solve 2023-02-20
// Update 2024-04-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    int x, y;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}
};

struct Bridge{
    int dist;
    Point from, to;

    Bridge(int dist, int x1, int y1, int x2, int y2) : dist(dist), from(x1, y1), to(x2, y2) {}

    bool operator<(const Bridge &rhs) const {
        return dist > rhs.dist;
    }
};

Point parent[10][10];
int max_children = 1;

Point get_parent_of(Point p) {
    if (parent[p.x][p.y].x < 0) return p;

    return parent[p.x][p.y] = get_parent_of(parent[p.x][p.y]);
}

bool union_parents(Point p1, Point p2) {
    p1 = get_parent_of(p1);
    p2 = get_parent_of(p2);

    if (p1.x != p2.x || p1.y != p2.y) {
        if (parent[p1.x][p1.y].x < parent[p2.x][p2.y].x) {
            parent[p1.x][p1.y].x += parent[p2.x][p2.y].x;
            parent[p2.x][p2.y] = { p1.x, p1.y };
            max_children = max(max_children, -parent[p1.x][p1.y].x);
        }
        else {
            parent[p2.x][p2.y].x += parent[p1.x][p1.y].x;
            parent[p1.x][p1.y] = { p2.x, p2.y };
            max_children = max(max_children, -parent[p2.x][p2.y].x);
        }

        return true;
    }

    return false;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int board[10][10];
    int area_sum = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> board[x][y];
            area_sum += board[x][y];
            parent[x][y] = { -1, 0 };
        }
    }

    priority_queue<Bridge> bridges;

    for (int x = 0; x < n; x++) {
        int py = -1;

        for (int y = 0; y < m; y++) {
            if (board[x][y] == 1) {
                if (py != -1 && y - py != 2) {
                    bridges.emplace(y - py - 1, x, py, x, y);
                }

                py = y;
            }
        }
    }

    for (int y = 0; y < m; y++) {
        int px = -1;

        for (int x = 0; x < n; x++) {
            if (board[x][y] == 1) {
                if (px != -1 && x - px != 2) {
                    bridges.emplace(x - px - 1, px, y, x, y);
                }

                px = x;
            }
        }
    }

    int bridge_dist_sum = 0;

    while (!bridges.empty()) {
        Bridge cur_bridge = bridges.top();
        bridges.pop();

        if (union_parents(cur_bridge.from, cur_bridge.to)) {
            bridge_dist_sum += cur_bridge.dist;
        }
    }

    cout << (area_sum == max_children ? bridge_dist_sum : -1) << '\n';

    return 0;
}

// Solve 2024-01-14
// Update 2024-02-15

#include <iostream>
using namespace std;

struct Point{
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    int get_dist_from(Point &p) {
        return abs(x - p.x) + abs(y - p.y);
    }
};

int n;
Point points[12];
int min_sum_dist;

void dfs(int depth, int prev, int selected, int sum_dist) {
    if (sum_dist >= min_sum_dist) return;

    if (depth == n + 2) {
        sum_dist += points[1].get_dist_from(points[prev]);

        if (sum_dist < min_sum_dist) {
            min_sum_dist = sum_dist;
        }

        return;
    }

    for (int i = 2; i < n + 2; i++) {
        if ((selected & 1 << i) != 0) continue;

        dfs(depth + 1, i, selected | 1 << i, sum_dist + points[i].get_dist_from(points[prev]));
    }
}

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        cin >> n;

        for (int i = 0; i < n + 2; i++) {
            cin >> points[i].x >> points[i].y;
        }

        min_sum_dist = 1000000;
        dfs(2, 0, 0, 0);

        cout << '#' << ti << ' ' << min_sum_dist << '\n';
    }

    return 0;
}

// Solve 2025-04-15

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1000000000;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Point> points;
    vector<int> x_list;
    vector<int> y_list;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.emplace_back(x, y);
        x_list.push_back(x);
        y_list.push_back(y);
    }

    sort(x_list.begin(), x_list.end());
    sort(y_list.begin(), y_list.end());
    vector<int> min_dist_sum_list(n, INF);

    for (int x : x_list) {
        for (int y : y_list) {
            vector<int> dists;

            for (Point &p : points) {
                dists.push_back(abs(x - p.x) + abs(y - p.y));
            }

            sort(dists.begin(), dists.end());
            int dist_sum = 0;

            for (int i = 0; i < n; i++) {
                dist_sum += dists[i];
                min_dist_sum_list[i] = min(min_dist_sum_list[i], dist_sum);
            }
        }
    }

    for (int &min_dist_sum : min_dist_sum_list) {
        cout << min_dist_sum << ' ';
    }

    cout << '\n';

    return 0;
}
